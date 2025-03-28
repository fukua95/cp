#include <bits/stdc++.h>

int main() {
  int t;
  std::cin >> t;
  while (t-- > 0) {
    int n, m, k;
    std::cin >> n >> m >> k;

    if (k % n == 0) {
      k = k / n;
    } else {
      k = k / n + 1;
    }

    // 变成 m 个格子，放 k 个人，使得相邻的人数的最大值尽量小
    // 贪心：当最大值是 i - 1，相当于每 i 个人隔一个空，那 m 个格子可以放 m/i * (i-1) + (m%i)
    // 找到最小的 i，使得 m/i * (i-1) + (m%i) >= k
    // m, k <= 10^9，不能枚举，得二分找最小的i，复杂度为 O(log2k)
    // 已经保证 m >= k
    int l = 1, r = k + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (m / mid * (mid - 1) + (m % mid) >= k) {
        r = mid;
      } else {
        l = mid;
      }
    }
    std::cout << r - 1 << std::endl;
  }
  return 0;
}