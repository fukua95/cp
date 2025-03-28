// problem: define f(a, b) = lcm(a, b) / gcd(a, b)，
// 问多少 (a, b) 满足 1 <= a < b <= n, f(a, b) 是质数?
//
// solution: 枚举质数，对于质数 p, f(a, b) = p 说明 b / a = p, b 整除 p,
// [1, n] 内有 n/p 个数整除 p，b 有 n/p 个, a = b/p，
// 所以对于 p, 有 n/p 对(a, b).

#include <bits/stdc++.h>

int main() {
  // init
  const int MAX = static_cast<int>(1e7 + 1);
  std::vector<bool> is_prime(MAX, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < MAX; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < MAX; j += i) {
        is_prime[j] = false;
      }
    }
  }

  int t;
  std::cin >> t;
  while (t-- > 0) {
    int n;
    std::cin >> n;
    int64_t ans = 0;
    for (int i = 2; i <= n; i++) {
      if (is_prime[i]) {
        ans += n / i;
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}