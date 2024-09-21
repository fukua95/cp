#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int MAXN = 2001;

std::vector<std::pair<int, int>> a;
int64_t f[MAXN][MAXN];

int64_t solve(int n) {
  std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
    return x > y; 
  });
  for (int i = 0; i < n; ++i) {
    int64_t val = a[i].first;
    int pos = a[i].second;
    for (int l = 0; l <= i + 1; ++l) {
      int r = i + 1 - l;
      int64_t temp = 0;
      if (l > 0) f[l][r] = f[l - 1][r] + val * std::abs(l - 1 - pos);
      if (r > 0) temp = f[l][r - 1] + val * std::abs(n - r - pos);
      if (temp > f[l][r]) f[l][r] = temp;
    }
  }
  int64_t ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (f[i][n - i] > ans) ans = f[i][n - i];
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0, u; i < n; ++i) {
    std::cin >> u;
    a.emplace_back(u, i);
  }
  std::cout << solve(n) << std::endl;
  return 0;
}
