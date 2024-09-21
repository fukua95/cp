#include <iostream>

const int MAXN = (int)1e5 + 1;
const int P = (int)1e9 + 7;

int64_t f[MAXN];  // gcd为i的倍数的方案数.
int64_t g[MAXN];  // gcd恰好为i的方案数.

int64_t pow(int64_t x, int y) {
  int64_t ans = 1;
  while (y > 0) {
    if (y & 1) ans = ans * x % P;
    x = x * x % P;
    y >>= 1;
  }
  return ans;
}

int64_t solve(int n, int k) {
  for (int i = 1; i <= k; ++i) {
    f[i] = pow(k / i, n);
  }
  for (int i = k; i >= 1; --i) {
    g[i] = f[i];
    for (int j = 2; j <= k / i; ++j) {
      g[i] = (g[i] - g[j * i] + P) % P;
    }
  }

  int64_t ans = 0;
  for (int i = 1; i <= k; ++i) {
    ans = (ans + g[i] * i % P) % P;
  }
  return ans;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::cout << solve(n, k) << std::endl;
  return 0;
}
