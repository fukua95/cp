#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0, a; i < n; ++i) {
      std::cin >> a;
      if (a % 2) {
        ++ans;
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}