#include <iostream>

using ll_t = long long;

int main() {
  int n;
  std::cin >> n;
  std::cout << (ll_t)n * (n - 1) / 2 << std::endl;
  return 0;
}
