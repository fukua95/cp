#include <iostream>

int64_t solve(int64_t x) {
  if (x == 1) return 1;
  return 1 + 2 * solve(x / 2);
}

int main() {
  int64_t h;
  std::cin >> h;
  std::cout << solve(h) << std::endl;
  return 0;
}
