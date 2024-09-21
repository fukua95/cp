#include <iostream>

int main() {
  int n, x;
  std::cin >> n >> x;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int a;
    std::cin >> a;
    if (a == x) {
      ans = i;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}