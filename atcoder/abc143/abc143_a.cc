#include <iostream>
#include <algorithm>

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << std::max(a - 2 * b, 0) << std::endl;
  return 0;
}
