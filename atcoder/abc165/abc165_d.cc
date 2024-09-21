#include <iostream>

int main() {
  int64_t a, b, n;
  std::cin >> a >> b >> n;
  int64_t x = n < b ? n : b - 1;
  int64_t ans = (a * x / b) - a * (x / b);
  std::cout << ans << std::endl;
  return 0;
}
