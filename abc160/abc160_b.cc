#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int ans = n / 500 * 1000;
  n %= 500;
  ans += n / 5 * 5;
  std::cout << ans << std::endl;
  return 0;
}
