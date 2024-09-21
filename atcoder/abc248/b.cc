#include <iostream>

int main() {
  int64_t a, b, k;
  std::cin >> a >> b >> k;
  int ans = 0;
  while (a < b) {
    a *= k;
    ++ans;
  }
  std::cout << ans << std::endl;
  return 0;
}