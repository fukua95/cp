#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int64_t ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 3 != 0 && i % 5 != 0) {
      ans += i;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
