#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 1; i <= n / 100; ++i) {
    int a = n - i * 100;
    if (a <= 5 * i) {
      ans = 1;
      break;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
