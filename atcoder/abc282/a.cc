#include <iostream>

int main() {
  int a;
  std::cin >> a;
  for (int i = 0; i < a; ++i) {
    std::cout << (char)('A' + i);
  }
  std::cout << std::endl;
  return 0;
}