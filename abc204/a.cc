#include <iostream>

int main() {
  int x, y, z;
  std::cin >> x >> y;
  if (x == y) z = x;
  else z = 3 - x - y;
  std::cout << z << std::endl;
  return 0;
}