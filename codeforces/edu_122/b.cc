#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    int one_count = 0;
    int zero_count = 0;
    for (auto ch : s) {
      if (ch == '0')
        ++zero_count;
      else
        ++one_count;
    }
    int ans;
    if (zero_count == one_count) {
      ans = s[0] == '0' ? zero_count - 1 : one_count - 1;
    } else {
      ans = zero_count < one_count ? zero_count : one_count;
    }
    std::cout << ans << std::endl;
  }
  return 0;
}