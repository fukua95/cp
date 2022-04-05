#include <cmath>
#include <iostream>

int solve(int x, int y) {
  if (x == 0 && y == 0) {
    return 0;
  }
  int s = std::sqrt(x * x + y * y);
  if (s * s == x * x + y * y) {
    return 1;
  } else {
    return 2;
  }
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int x, y;
    std::cin >> x >> y;
    std::cout << solve(x, y) << std::endl;
  }
  return 0;
}