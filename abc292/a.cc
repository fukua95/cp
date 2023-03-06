#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    s[i] = s[i] - 32;
  }
  std::cout << s << std::endl;
  return 0;
}