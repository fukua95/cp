#include <iostream>
#include <cmath>

using ll_t = long long;

int main() {
  ll_t n;
  std::cin >> n;
  int sqrt = std::sqrt(n + 0.5);
  ll_t ans = 0;
  for (int i = sqrt; i > 0; --i) {
    if (n % i == 0) {
      ans = n / i + i - 2;
      break;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
