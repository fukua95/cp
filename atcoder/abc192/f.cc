#include <iostream>
#include <vector>
#include <assert.h>

const int MAXN = 101;

int64_t f[MAXN][MAXN][MAXN];

int64_t calc(const std::vector<int>& a, int m, int x) {
  int n = a.size() - 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k < m; ++k) {
        f[i][j][k] = -1;
      }
    }
  }
  f[0][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    f[i][0][0] = 0;
    for (int j = 1; j <= i; ++j) {
      for (int k = 0; k < m; ++k) {
        if (j < i) f[i][j][k] = f[i - 1][j][k];
        int v = (k + m - a[i] % m) % m;
        if (f[i - 1][j - 1][v] < 0) continue;
        f[i][j][k] = std::max(f[i][j][k], f[i - 1][j - 1][v] + a[i]);
      }
    }
  }
  return f[n][m][x];
}

int main() {
  int n;
  int64_t x;
  std::cin >> n >> x;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i)
    std::cin >> a[i];

  int64_t ans = x;
  for (int k = 1; k <= n; ++k) {
    int64_t cur = calc(a, k, x % k);
    if (cur < 0) continue;
    assert((x - cur) % k == 0);
    cur = (x - cur) / k;
    if (cur < ans) ans = cur;
  }
  std::cout << ans << std::endl;
  return 0;
}