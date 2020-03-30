#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  if (s[2] == s[3] && s[4] == s[5]) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
