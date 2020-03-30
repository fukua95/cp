#include <iostream>

int main() {
  int n, m, a, b;
  std::cin >> n >> m >> a >> b;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((i < b && j < a) || (i >= b && j >= a)) std::cout << "1";
      else std::cout << "0";
    }
    std::cout << std::endl;
  }
  return 0;
}
