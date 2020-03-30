#include <iostream>
#include <algorithm>

using ll_t = long long;
const int MAXN = 2000;

int a[MAXN];

ll_t solve(int n) {
  std::sort(a, a + n);
  ll_t res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (i == j) continue;
      int max = a[i] + a[j];
      int min = a[j] > a[i] ? a[j] - a[i] : a[i] - a[j];
      int num = std::lower_bound(a, a + n, max) - a - 
                (std::lower_bound(a, a + n, min + 1) - a);
      if (min < a[i] && a[i] < max) --num;
      if (min < a[j] && a[j] < max) --num;
      // std::cout << a[i] << " " << a[j] << " min=" << min << " max=" << max << " num=" << num << std::endl;
      res += num;
    }
  }
  return res / 3;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::cout << solve(n) << std::endl;
  return 0;
}
