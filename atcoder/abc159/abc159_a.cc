#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::cout << (n - 1) * n / 2 + (m - 1) * m / 2 << std::endl;
  return 0;
}
