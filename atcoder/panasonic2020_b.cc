#include <iostream>

int64_t solve(int64_t a, int64_t b) {
  if (a == 1 || b == 1) return 1;
  return b / 2 * a + b % 2 * ((a + 1) / 2);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << solve(a, b) << std::endl;
  return 0;
}
