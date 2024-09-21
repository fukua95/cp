#include <iostream>

int main() {
  int a, b, c, x;
  std::cin >> a >> b >> c >> x;
  double ans = 0;
  if (x <= a) {
    ans = 1;
  } else if (x <= b) {
    ans = (c + 0.0) / (b - a);
  }
  std::cout << ans << std::endl;

  return 0;
}