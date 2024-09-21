#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    sum += a[i];
  }

  std::vector<bool> f(sum + 1, false);
  f[0] = true;
  for (int i = 0; i < n; ++i) {
    for (int j = sum; j > 0; --j) {
      if (j - a[i] >= 0 && f[j - a[i]]) {
        f[j] = true;
      }
    }
  }
  int ans = sum;
  for (int i = 1; i < sum; ++i) {
    if (f[i]) {
      // std::cout << "i = " << i << std::endl;
      int ma = (sum - i) > i ? (sum - i) : i;
      if (ma < ans) ans = ma;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}