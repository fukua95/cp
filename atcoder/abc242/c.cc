#include <iostream>
#include <vector>

int main() {
  const int P = 998244353;

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> f(n, std::vector<int>(10, 0));
  for (int i = 1; i <= 9; ++i) {
    f[0][i] = 1;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= 9; ++j) {
      f[i][j] = f[i - 1][j];
      if (j - 1 >= 1) f[i][j] = (f[i][j] + f[i - 1][j - 1]) % P;
      if (j + 1 <= 9) f[i][j] = (f[i][j] + f[i - 1][j + 1]) % P;
    }
  }
  int64_t ans = 0;
  for (int i = 1; i <= 9; ++i) {
    ans = (ans + f[n - 1][i]) % P;
  }
  std::cout << ans << std::endl;
  return 0;
}