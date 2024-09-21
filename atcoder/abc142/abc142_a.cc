#include <iostream>

int main() {
  int n;
  std::cin >> n;
  if (n % 2 == 0) std::cout << "0.5" << std::endl;
  else std::cout << (n + 1.0) / (2.0 * n) << std::endl;
  return 0;
}
