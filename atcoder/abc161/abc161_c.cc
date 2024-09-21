#include <iostream>
#include <algorithm>

int main() {
  int64_t a, b;
  std::cin >> a >> b;
  std::cout << std::min(a % b, b - a % b) << std::endl;
  return 0;
}
