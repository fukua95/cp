#include <iostream>
#include <vector>
#include <algorithm>

const int INF = (int)1e9;

int min_op_num(const std::vector<int>& a, int l, int r) {
  std::vector<int> f(r - l, INF);
  f[0] = -INF;
  for (int i = l + 1; i < r; ++i) {
    if (a[i] < a[l] || a[i] > a[r]) continue;
    auto iter = std::upper_bound(f.begin(), f.end(), a[i]);
    if (iter != f.end()) *iter = a[i];
  }

  for (int i = r - l - 1; i > 0; --i) {
    // std::cout << "i = " << i << "f = " << f[i] << std::endl;
    if (f[i] != INF) return r - l - 1 - i;
  }
  return r - l - 1;  // r - l - 1 - 0;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  n += 2, k += 2;
  std::vector<int> a(n), sep(k);
  a[0] = -INF, a[n - 1] = INF;
  sep[0] = 0, sep[k - 1] = n - 1;
  for (int i = 1; i < n - 1; ++i) std::cin >> a[i];
  for (int i = 1; i < k - 1; ++i) std::cin >> sep[i];

  for (int i = 1; i < n - 1; ++i) a[i] -= i;

  int ans = 0;
  for (int i = 0; i < k - 1; ++i) {
    int l = sep[i], r = sep[i + 1];
    if (a[l] > a[r]) {
      ans = -1;
      break;
    }
    ans += min_op_num(a, l, r);
  }
  std::cout << ans << std::endl;
  return 0;
}