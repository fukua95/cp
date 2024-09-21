#include <iostream>

int solve(int n, int r) {
  if (n >= 10) return r;
  return r + 1000 - 100 * n;
}

int main() {
  int n, r;
  std::cin >> n >> r;
  std::cout << solve(n, r) << std::endl;
  return 0;
}
