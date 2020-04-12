#include <iostream>
#include <string>

const int MAXN = 4001;

int r[MAXN], g[MAXN], b[MAXN];

int64_t solve(int n, const std::string& s) {
  r[n] = g[MAXN] = b[MAXN] = 0;
  for (int i = n - 1; i >= 0; --i) {
    r[i] = r[i + 1];
    g[i] = g[i + 1];
    b[i] = b[i + 1];
    if (s[i] == 'R') ++r[i];
    else if (s[i] == 'G') ++g[i];
    else ++b[i];
  }

  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (s[i] == s[j]) continue;
      int *p;
      char ch = 'R';
      if (s[i] != 'R' && s[j] != 'R') p = r, ch = 'R';
      else if (s[i] != 'G' && s[j] != 'G') p = g, ch = 'G';
      else p = b, ch = 'B';
      ans += p[j + 1];
      if (j + j - i < n && s[j + j - i] == ch) --ans;
    }
  }
  return ans;
}

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;
  std::cout << solve(n, s) << std::endl;
  return 0;
}
