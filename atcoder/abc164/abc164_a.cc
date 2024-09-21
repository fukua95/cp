#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  if (b >= a) std::cout << "unsafe" << std::endl;
  else std::cout << "safe" << std::endl;
  return 0;
}
