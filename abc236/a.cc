#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int a, b;
  std::cin >> a >> b;
  std::swap(s[a - 1], s[b - 1]);
  std::cout << s << std::endl;
  return 0;
}