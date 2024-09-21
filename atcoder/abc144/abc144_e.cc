#include <iostream>
#include <algorithm>

using ll_t = long long;
const int MAXN = (int)2e5;

int a[MAXN], f[MAXN];

ll_t min_op_num(int n, ll_t limit) {
  ll_t res = 0;
  for (int i = 0; i < n; ++i) {
    ll_t cur = limit / f[i];
    res += std::max((ll_t)a[i] - cur, (ll_t)0);
  }
  return res;
}

ll_t solve(int n, ll_t k) {
  std::sort(f, f + n, [](int x, int y) {return x > y;});
  std::sort(a, a + n);
  
  ll_t l = -1, r = (ll_t)a[0] * f[0];
  for (int i = 1; i < n; ++i) {
    if ((ll_t)a[i] * f[i] > r) {
      r = (ll_t)a[i] * f[i];
    }
  }
  while (r - l > 1) {
    ll_t mid = (l + r) >> 1;
    if (min_op_num(n, mid) > k) l = mid;
    else r = mid;
  }
  return r;
}

int main() {
  int n;
  ll_t k;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> f[i];
  std::cout << solve(n, k) << std::endl;
  return 0;
}
