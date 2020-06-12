#include <iostream>

const int MAXN = 3001;
const int P = 998244353;

int a[MAXN];
int f[MAXN][MAXN];

int pow(int64_t x, int y) {
  int64_t ans = 1;
  while (y > 0) {
    if (y & 1) ans = ans * x % P;
    x = x * x % P;
    y >>= 1;
  }
  return ans;
}

int solve(int n, int sum) {
  for (int i = 1; i <= n; ++i) {
    f[i][a[i]] = pow(2, i - 1);
    for (int j = 1; j <= sum; ++j) {
      f[i][j] = (f[i][j] +  2LL * f[i - 1][j]) % P;
      if (j - a[i] > 0) {
        f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % P;
      }
    }
  }
  return f[n][sum];
}

int main() {
  int n, sum;
  std::cin >> n >> sum;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  std::cout << solve(n, sum) << std::endl;
  return 0;
}
