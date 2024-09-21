#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    std::cout << 'x';
  }
  std::cout << std::endl;
  return 0;
}
