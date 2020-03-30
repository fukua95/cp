#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

const int MAXN = 101;

int rem[MAXN][2][4];

int dfs(int p, int limit, int pre, const std::string& s, int k) {
  if (p == -1) return pre == k;
  if (rem[p][limit][pre] != -1) return rem[p][limit][pre];
  int ans = 0;
  int n = s[p] - '0';
  for (int i = 0; i <= 9; ++i) {
    if (limit && i > n) break;
    int cur = pre + (i > 0);
    if (cur > k) break;
      ans += dfs(p - 1, limit && (i == n), cur, s, k);
  }
  rem[p][limit][pre] = ans;
  return ans;
}

int solve(const std::string& s, int k) {
  memset(rem, -1, sizeof(rem));
  return dfs((int)s.length() - 1, 1, 0, s, k);
}

int main() {
  std::string s;
  int k;
  std::cin >> s >> k;
  std::reverse(s.begin(), s.end());
  std::cout << solve(s, k) << std::endl;
  return 0;
}
