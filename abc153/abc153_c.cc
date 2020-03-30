#include <iostream>
#include <algorithm>

const int MAXN = (int)2e5;

int a[MAXN];

int64_t solve(int n, int k) {
  std::sort(a, a + n);
  int64_t sum = 0;
  for (int i = 0; i < n - k; ++i) {
    sum += a[i];
  }
  return sum;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::cout << solve(n, k) << std::endl;
  return 0;
}
