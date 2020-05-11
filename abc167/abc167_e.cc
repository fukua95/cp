#include <iostream>
#include <vector>

const int MAXN = (int)2e5 + 1;;
const int P = 998244353;

int fact[MAXN];

void init(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) 
    fact[i] = (int64_t)fact[i - 1] * i % P;
}

int64_t pow(int64_t x, int y) {
  x %= P;
  int64_t ans = 1;
  while (y > 0) {
    if (y & 1) ans = ans * x % P;
    x = x * x % P;
    y >>= 1;
  }
  return ans;
}

int64_t comb(int x, int y) {
  return fact[x] * pow((int64_t)fact[y] * fact[x - y], P - 2) % P;
}

// n个格子，m种颜色，最多有k对相邻格子是同一种颜色，求方案数.
// 枚举i = 0 -> k, 对于刚好有i对相邻格子是同一种颜色的情况，推公式.
int solve(int n, int m, int k) {
  init(n);
  int64_t ans = 0;
  for (int i = 0; i <= k; ++i) {
    int64_t cur = m * pow(m - 1, n - 1 - i) % P * comb(n - 1, i) % P;
    ans = (ans + cur) % P;
  }
  return ans;
}

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::cout << solve(n, m, k) << std::endl;
  return 0;
}
