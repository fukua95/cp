#include <iostream>
#include <vector>

int main() {
  int n, l, m;
  std::cin >> n >> l >> m;
  std::vector<int> a(n + 1), d(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> d[i];
  }
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  const int INF = (int)1e9 + 1;
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, INF));
  f[1][1] = 0;
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= i; ++j) {
      for (int k = 1; k < i; ++k) {
        int cur = f[k][j - 1] + (d[i] - d[k]) * a[k];
        if (cur < f[i][j]) {
          f[i][j] = cur;
        }
      }
    }
  }
  int ans = INF;
  for (int i = 1; i <= n; ++i) {
    for (int j = n - m; j <= n; ++j) {
      int cur = f[i][j] + (l - d[i]) * a[i];
      if (cur < ans) {
        ans = cur;
      }
    }
  }
  std::cout << ans << std::endl;
  return 0;
}