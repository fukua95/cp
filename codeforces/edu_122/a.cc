#include <iostream>

int main() {
  int t, n;
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    int ans = n;
    if (n % 7 != 0) {
      int rem = n % 7;
      if (n % 10 - rem >= 0) {
        ans -= rem;
      } else {
        ans += (7 - rem);
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}