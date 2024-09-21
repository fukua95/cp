#include <iostream>

int main() {
  int m, d;
  std::cin >> m >> d;
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 20; j <= d; ++j) {
      int a = j % 10;
      int b = j - a;
      if (a >= 2 && b / 10 * a == i) ++ans;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
