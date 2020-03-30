#include <iostream>
#include <algorithm>

const int MAXN = 50;

double a[MAXN];

double solve(int n) {
  std::sort(a, a + n);
  double res = a[0];
  for (int i = 1;i < n; ++i) {
    res = (res + a[i]) / 2.0;
  }
  return res;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::cout << solve(n) << std::endl;
  return 0;
}
