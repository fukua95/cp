#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> count(n + 1, 0);
    for (int i = 0, a; i < n; ++i) {
      std::cin >> a;
      count[a] += 1;
    }

    std::vector<bool> used(n + n, false);
    std::vector<int> pending;
    pending.emplace_back(0);
    for (int i = 1; i <= n; ++i) {
      if (count[i] >= 1) {
        used[i] = true;
        for (int j = 2; j <= count[i]; ++j) {
          pending.emplace_back(i);
        }
      }
    }

    std::vector<std::vector<int>> f(2 * n, std::vector<int>(pending.size(), 100000));
    f[0][0] = 0;
    for (int i = 1; i < 2 * n; ++i) {
      f[i][0] = 0;
      for (int j = 1; j < pending.size(); ++j) {
        if (used[i]) {
          f[i][j] = f[i - 1][j];
        } else {
          f[i][j] = std::min(f[i - 1][j - 1] + std::abs(pending[j] - i), f[i - 1][j]);
        }
      }
    }

    std::cout << f[2 * n - 1][pending.size() - 1] << std::endl;
  }
  return 0;
}