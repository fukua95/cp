#include <iostream>

int main() {
  int h, w, n;
  std::cin >> h >> w >> n;
  if (w > h) h = w;
  std::cout << (n + h - 1) / h << std::endl;
  return 0;
}
