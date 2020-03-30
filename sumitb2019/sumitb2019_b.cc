#include <iostream>

int main() {
  int n;
  std::cin >> n;
  n *= 100;
  int a = (n + 107) / 108;
  if (a * 108 / 100 != n / 100) std::cout << ":(" << std::endl;
  else std::cout << a << std::endl;
  return 0;
}
