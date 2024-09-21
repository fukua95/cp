#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, limit, x, y;
    std::cin >> n >> limit >> x >> y;
    int64_t sum = 0;
    int cur = 0;
    int pos = 1;
    while (pos <= n) {
      if (cur + x <= limit) {
        cur += x;
      } else {
        cur -= y;
      }
      sum += cur;
      ++pos;
    }
    std::cout << sum << std::endl;
  }
  return 0;
}