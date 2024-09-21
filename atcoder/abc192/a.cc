#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int a = (n + 99) / 100 * 100 - n;
  if (a == 0) a += 100;
  std::cout << a << std::endl;
  return 0;
}
