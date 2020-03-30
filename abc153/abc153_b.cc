#include <iostream>

int main() {
  int h, n, sum = 0;
  std::cin >> h >> n;
  for (int i = 0, a; i < n; ++i) {
    std::cin >> a;
    sum += a;
  }
  if (sum >= h) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
