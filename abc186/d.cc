#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());
  int64_t ans = 0;
  int64_t sum = a[0];
  for (int i = 1; i < n; ++i) {
    ans += (int64_t)a[i] * i - sum;
    sum += a[i];
  }
  std::cout << ans << std::endl;
  return 0;
}