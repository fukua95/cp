#include <iostream>
#include <vector>
#include <string>
#include <set>

bool check(const std::vector<int>& digit, int64_t base, int64_t inf) {
  int n = digit.size();
  int64_t val = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (val > inf / base) return false;
    val = (val * base + digit[i]);
    if (val > inf) return false;
  }
  return true;
}

int64_t solve(const std::string& s, int64_t inf) {
  int n = s.length();
  int ma = 0;
  std::vector<int> digit(n);
  for (int i = 0; i < n; ++i) {
    digit[i] = s[n - 1 - i] - '0';
    if (digit[i] > ma) ma = digit[i];
  }

  if (n == 1) return digit[0] <= inf ? 1 : 0;  // 特殊情况
  if (!check(digit, ma + 1, inf)) return 0;
  int64_t l = ma + 1, r = inf + 1;
  while (r - l > 1) {
    int64_t mid = (l + r) / 2;
    if (check(digit, mid, inf)) l = mid;
    else r = mid;
  }
  return l - ma;
}

int main() {
  std::string s;
  int64_t inf;
  std::cin >> s >> inf;
  std::cout << solve(s, inf) << std::endl;
  return 0;
}
