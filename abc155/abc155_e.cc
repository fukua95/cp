#include <iostream>
#include <algorithm>
#include <string>

const int MAXN = 1e6 + 1;
int f[MAXN][2];

int solve(const std::string& s) {
  int n = s.length();
  f[0][0] = s[n - 1] - '0';
  f[0][1] = 11 - (s[n - 1] - '0');
  for (int i = 1; i < n; ++i) {
    int cur = s[n - 1 - i] - '0';
    f[i][0] = std::min(f[i - 1][0], f[i - 1][1]) + cur;
    f[i][1] = std::min(f[i - 1][0] + 11 - cur, f[i - 1][1] + 9 - cur);
  }
  return std::min(f[n - 1][0], f[n - 1][1]);
}

int main() {
  std::string s;
  std::cin >> s;
  std::cout << solve(s) << std::endl;
  return 0;
}
