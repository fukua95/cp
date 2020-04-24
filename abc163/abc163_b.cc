#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int val;
    std::cin >> val;
    n -= val;
  }
  if (n < 0) n = -1;
  std::cout << n << std::endl;
  return 0;
}
