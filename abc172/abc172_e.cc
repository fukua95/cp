#include <iostream>

const int P = (int)1e9 + 7;
const int MAXN = (int)5e5 + 1;

int factorial[MAXN];
int comb[MAXN];       // comb[i] = C(n, i).

int64_t inv(int64_t x) {
  int64_t ans = 1, y = P - 2;
  while (y > 0) {
    if (y & 1) ans = ans * x % P;
    x = x * x % P;
    y >>= 1;
  }
  return ans;
}

void init(int n, int m) {
  factorial[0] = 1;
  for (int i = 1; i <= m; ++i) {
    factorial[i] = factorial[i - 1] * 1LL * i % P;
  }
  comb[0] = 1;
  for (int i = 1; i <= n; ++i) {
    comb[i] = comb[i - 1] * 1LL * (n - i + 1) % P * inv(i) % P;
  }
}

int64_t per(int x, int y) {
  return 1LL * factorial[x] * inv(factorial[x - y]) % P;
}

int solve(int n, int m) {
  init(n, m);
  int64_t ans = 0;
  int sign = 1;
  for (int i = 0; i <= n; ++i) {
    ans += sign * per(m - i, n - i) * comb[i];
    ans %= P;
    sign = sign == 1 ? -1 : 1;
  }
  ans = (ans + P) * per(m, n) % P;
  return ans;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::cout << solve(n, m) << std::endl;
  return 0;
}

