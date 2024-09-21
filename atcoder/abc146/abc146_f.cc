#include <iostream>
#include <utility>
#include <string>
#include <set>

using pii = std::pair<int, int>;
const int MAXN = (int)1e5 + 1;
const int INF = MAXN;

pii f[MAXN];  // dp.

void solve(int n, int m, const std::string &str) {
  f[n] = std::make_pair(0, n);
  std::set<pii> rem;
  rem.emplace(f[n]);
  for (int l = n - 1, r = l + m; l >= 0; --l, --r) {
    if (str[l] == '1') {
      f[l] = std::make_pair(INF, l);
    } else {
      f[l] = *rem.begin();
      ++f[l].first;
    }
    if (r <= n) {
      pii erase = std::make_pair(f[r].first, r);
      auto iter = rem.find(erase);
      if (iter != rem.end()) rem.erase(iter);
    }
    rem.emplace(f[l].first, l);
  }
}

int main() {
  int n, m;
  std::string str;
  std::cin >> n >> m >> str;
  
  solve(n, m, str);
  
  if (f[0].first >= INF) {
    std::cout << "-1" << std::endl;
  } else {
    int pos = 0;
    while (pos < n) {
      std::cout << f[pos].second - pos << " ";
      pos = f[pos].second;
    }
    std::cout << std::endl;
  }
  return 0;
}
