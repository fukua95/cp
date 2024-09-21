#include <iostream>
#include <vector>

const int P = 998244353;

int main() {
  int n, m, limit;
  std::cin >> n >> m >> limit;

  // solve
  // f[i][j]表示前i个数，和=j的方案数
  std::vector<std::vector<int64_t>> f(n + 1,
                                      std::vector<int64_t>(n * m + 1, 0));

  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= limit; ++j) {
      f[i][j] = 0;
      for (int k = 1; k <= m; ++k) {
        if (j >= k) {
          f[i][j] = (f[i][j] + f[i - 1][j - k]) % P;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= limit; ++i) {
    ans = (ans + f[n][i]) % P;
  }
  std::cout << ans << std::endl;
  return 0;
}