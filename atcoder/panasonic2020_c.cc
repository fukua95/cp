#include <iostream>
#include <cmath>

bool solve(int a, int b, int c) {
  int64_t cur = c - a - b;
  return cur > 0 && ((int64_t)4 * a * b < cur * cur);
}

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if (solve(a, b, c)) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
