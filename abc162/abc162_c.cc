#include <iostream>

int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

int solve(int k) {
  int ans = 0;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= k; ++j) {
      int d1 = gcd(i, j);
      for (int c = 1; c <= k; ++c) {
        ans += gcd(d1, c);
      }
    }
  }
  return ans;
}

int main() {
  int k;
  std::cin >> k;
  std::cout << solve(k) << std::endl;
  return 0;
}
