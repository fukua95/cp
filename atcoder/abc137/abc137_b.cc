#include <iostream>
#include <algorithm>

int main() {
  int l = -1000000;
  int r = 1000000;
  int k, x;
  std::cin >> k >> x;
  int nl = std::max(l, x - k + 1);
  int nr = std::min(r, x + k - 1);
  for (int i = nl; i <= nr; ++i) std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
