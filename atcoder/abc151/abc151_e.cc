#include <iostream>
#include <algorithm>

using ll_t = int64_t;

const int MAXN = (int)1e5 + 1;
const int P = (int)1e9 + 7;

int a[MAXN];
ll_t factorial[MAXN];

void init(int n) {
  factorial[0] = 1;
  for (int i = 1; i <= n; ++i) {
    factorial[i] = factorial[i - 1] * i % P;
  }
}

// Calc x ^(P - 2) % P.
ll_t inv(ll_t x) {
  x %= P;
  int y = P - 2;
  ll_t res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % P;
    x = x * x % P;
    y >>= 1;
  }
  return res;
}

// Calc C(x, y). 
ll_t comb(int x, int y) {
  if (x < y) return 0;
  if (y == 0 || y == x) return 1;
  return factorial[x] * inv (factorial[y] * factorial[x - y]) % P;
}

ll_t calc(int n, int k) {
  std::sort(a + 1, a + n + 1);
  ll_t res = 0;
  for (int i = 1; i <= n; ++i) {
    res = (res + comb(i - 1, k - 1) * a[i] % P) % P;
  }
  return res;
}

int64_t solve(int n, int k) {
  init(n);
  ll_t res1 = calc(n, k);
  for (int i = 1; i <= n; ++i) a[i] = -a[i];
  ll_t res2 = calc(n, k);
  return (res1 + res2) % P;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  std::cout << solve(n, k) << std::endl;
  return 0;
}
