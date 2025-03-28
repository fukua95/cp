// problem: 一个组的值 = min * num, 问一些数，最多能组成多少个组，使得每个组的值 >= x.
// solution: 贪心

#include <bits/stdc++.h>

int main() {
  int t;
  std::cin >> t;
  while (t-- != 0) {
    int n;
    int x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    int ans = 0;
    std::sort(a.begin(), a.end(), [](int i, int j) { return i > j; });
    int l = 0;
    int r = 0;
    while (r < n) {
      int64_t cur = static_cast<int64_t>(a[r]) * (r - l + 1);
      if (cur >= x) {
        ++ans;
        l = r + 1;
      }
      r++;
    }

    std::cout << ans << std::endl;
  }
  return 0;
}