#include <iostream>
#include <map>
#include <string>

int64_t solve(std::string &s) {
  std::map<int, int> count;
  int val = 0;
  int base = 1;
  int P = 2019;
  for (int i = s.length() - 1; i >= 0; --i) {
    val += (int)(s[i] - '0') * base;
    val %= P;
    ++count[val];
    base = base * 10 % P;
  }
  ++count[0];
  int64_t ans = 0;
  for (const auto &[val, num] : count) {
    (void)val;
    ans += (int64_t)num * (num - 1) / 2;
  }
  return ans;
}

int main() {
  std::string s;
  std::cin >> s;
  std::cout << solve(s) << std::endl;
  return 0;
}
