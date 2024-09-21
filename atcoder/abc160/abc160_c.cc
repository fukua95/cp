#include <iostream>

const int MAXN = (int)2e5;

int a[MAXN];

int solve(int n, int k) {
  int max_dis = a[0] + k - a[n - 1];
  for (int i = 1; i < n; ++i) {
    int cur = a[i] - a[i - 1];
    if (cur > max_dis) max_dis = cur;
  }
  return k - max_dis;
}

int main() {
  int k, n;
  std::cin >> k >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::cout << solve(n, k) << std::endl;
  return 0;
}
