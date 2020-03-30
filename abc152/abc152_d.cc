#include <iostream>

int a[10][10];

int calc_msu(int x) {
  while (x >= 10) {
    x /= 10;
  }
  return x;
}

int solve(int n) {
  for (int i = 1; i <= n; ++i) {
    int msu = calc_msu(i);
    int lsu = i % 10;
    ++a[msu][lsu];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int msu = calc_msu(i);
    int lsu = i % 10;
    ans += a[lsu][msu];
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << solve(n) << std::endl;
  return 0;
}
