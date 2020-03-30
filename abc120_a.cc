#include <iostream>
#include <cmath>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << std::min(b / a, c) << std::endl;
  return 0;
}
