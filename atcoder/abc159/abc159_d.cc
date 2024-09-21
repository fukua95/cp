#include <iostream>
#include <map>

const int MAXN = (int)2e5;

int a[MAXN];

void solve(int n) {
  std::map<int, int> num_count;
  for (int i = 0; i < n; ++i) {
    ++num_count[a[i]];
  }
  int64_t ans = 0;
  for (const auto& cur : num_count) {
    int val = cur.first, cnt = cur.second;
    ans += (int64_t)(cnt - 1) * cnt / 2;
  }
  for (int i = 0; i < n; ++i) {
    std::cout << ans - (num_count[a[i]] - 1) << std::endl;
  }
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  solve(n);
  return 0;
}
