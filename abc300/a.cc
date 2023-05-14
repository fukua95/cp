#include <iostream>

int main() {
  int n, a, b;
  std::cin >> n >> a >> b;
  int ans = 0;
  a += b;
  for (int i = 1; i <= n; ++i) {
    int c;
    std::cin >> c;
    if (c == a) {
      ans = i;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}