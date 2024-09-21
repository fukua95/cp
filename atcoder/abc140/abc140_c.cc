#include <iostream>
#include <algorithm>

const int MAXN = 100;

int b[MAXN];

int solve(int n) {
  int res = b[0] + b[n - 2];
  for (int i = 1; i < n - 1; ++i) {
    res += std::min(b[i - 1], b[i]);
  }
  return res;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n - 1; ++i) std::cin >> b[i];
  std::cout << solve(n) << std::endl;
  return 0;
}
