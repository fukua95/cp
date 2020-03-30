#include <iostream>
#include <algorithm>
#include <string>

int solve(int n, int k, const std::string &s) {
  int same = 0, len = s.length();
  for (int i = 1; i < len; ++i) {
    if (s[i] == s[i - 1]) ++same;
  }
  return same + std::min(len - 1 - same, 2 * k);
}

int main() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  std::cout << solve(n, k, s) << std::endl;
  return 0;
}
