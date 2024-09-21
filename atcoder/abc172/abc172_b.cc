#include <iostream>
#include <string>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  int count = 0;
  int len = s.length();
  for (int i = 0; i < len; ++i) {
    if (s[i] != t[i]) {
      ++count;
    }
  }
  std::cout << count << std::endl;
  return 0;
}
