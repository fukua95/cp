#include <iostream>
#include <cmath>

// Find the max x that s.t. (1+x) * x / 2 <= n.
int binary_search(int n) {
  n *= 2;
  int l = 1, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if ((1 + mid) * mid <= n) l = mid;
    else r = mid;
  }
  return l;
}

int solve(int64_t n) {
  int ans = 0;
  int sqrt = std::sqrt(n + 0.5);
  for (int i = 2; i <= sqrt; ++i) {
    if (n % i == 0) {
      int num = 0;
      while (n % i == 0) {
        n /= i;
        ++num;
      }
      ans += binary_search(num);
    }
  }
  if (n > 1) ++ans;
  return ans;
}

int main() {
  int64_t n;
  std::cin >> n;
  std::cout << solve(n) << std::endl;
  return 0;
}
