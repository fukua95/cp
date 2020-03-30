#include <iostream>
#include <string>

int solve(const std::string &s) {
  char cur = s[0];
  int len = s.length();
  int res = 1;
  for (int i = 1; i < len; ++i) {
    if (s[i] == cur) continue;
    ++res;
    cur = s[i];
  }
  return res;
}

int main() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::cout << solve(s) << std::endl;
  return 0;
}
