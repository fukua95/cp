#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    int j = n - i;
    if (j <= i) break;
    ++ans;
  }
  std::cout << ans << std::endl;
  return 0;
}
