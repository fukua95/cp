#include <iostream>

int main() {
  int n;
  int ans = 0;
  std::cin >> n;
  for (int i = 0, a; i < n; ++i) {
    std::cin >> a;
    if (a > 10) ans += a - 10;
  }
  std::cout << ans << std::endl;
  return 0;
}