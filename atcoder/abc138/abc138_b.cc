#include <iostream>

int main() {
  int n;
  double ans = 0.0;
  std::cin >> n;
  for (int i = 0, a; i < n; ++i) {
    std::cin >> a;
    ans += 1.0 / a;
  }
  std::cout << 1.0 / ans << std::endl;
  return 0;
}
