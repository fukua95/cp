#include <iostream>

const int P = (int)1e9 + 7;

int solve(int n, int k) {
  int64_t ans = 0;
  for (int i = k; i <= n + 1; ++i) {
    int64_t max = (int64_t)i * (2 * n - i + 1) / 2;
    int64_t min = (int64_t)i * (i - 1) / 2;
    ans = (ans + max - min + 1) % P;
    // std::cout << "i = " << i << " f = " << max - min + 1 << std::endl;
  }
  return ans;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::cout << solve(n, k) << std::endl;
  return 0;
}
