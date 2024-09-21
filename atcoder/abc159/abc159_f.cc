#include <iostream>
#include <cstring>

const int MAXN = 3002;
const int P = 998244353;

int a[MAXN];
int64_t f[2][MAXN];

int64_t solve(int n, int sum) {
  memset(f, 0, sizeof(f));
  int64_t ans = 0;
  int mask = 0;
  for (int i = n; i > 0; --i) {
    mask ^= 1;
    if (sum > a[i]) ans += i * f[mask ^ 1][sum - a[i]];
    else if (sum == a[i]) ans += i * (n + 1 - i);
    ans %= P;

    for (int j = 1; j <= sum; ++j) {
      f[mask][j] = f[mask ^ 1][j];
      if (j >= a[i]) f[mask][j] = (f[mask][j] + f[mask ^ 1][j - a[i]]) % P;
    }
    f[mask][a[i]] += n + 1 - i;
  }
  return ans;
}

int main() {
  int n, sum;
  std::cin >> n >> sum;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::cout << solve(n, sum) << std::endl;
  return 0;
}
