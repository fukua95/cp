#include <iostream>

const int MAXN = (int)1e7 + 1;

int divisor_num[MAXN];

int64_t solve(int n) {
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      ++divisor_num[j];
    }
  }
  int64_t ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += 1LL * i * divisor_num[i];
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << solve(n) << std::endl;
  return 0;
}
