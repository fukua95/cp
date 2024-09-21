#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  int ans = a == c ? 0 : 1;
  std::cout << ans << std::endl;
  return 0;
}
