#include <cmath>
#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int64_t n;
    std::cin >> n;
    int64_t x, y;
    for (int64_t i = 2; i * i * i <= n; ++i) {
      if (n % i != 0) continue;
      if ((n / i) % i == 0) {
        x = i;
        y = n / i / i;
      } else {
        y = i;
        x = std::round(std::sqrt(n / i));
      }
      break;
    }
    std::cout << x << " " << y << std::endl;
  }
  return 0;
}