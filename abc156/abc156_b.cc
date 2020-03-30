#include <iostream>

int solve(int n, int k) {
  int ans = 1;
  while (n >= k) {
    ++ans;
    n /= k;
  }
  return ans;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::cout << solve(n, k) << std::endl;
  return 0;
}
