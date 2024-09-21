#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, l;
    std::cin >> n >> l;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < l; ++i) {
      int one_count = 0;
      int zero_count = 0;
      for (int j = 0; j < n; ++j) {
        if (a[j] & (1 << i)) {
          ++one_count;
        } else {
          ++zero_count;
        }
      }
      if (one_count > zero_count) {
        ans += (1 << i);
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}