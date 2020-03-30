#include <iostream>

const int MAXN = 100;

int a[MAXN];

int solve(int n) {
  int ans = -1;
  for (int i = 1; i <= 100; ++i) {
    int cur = 0;
    for (int j = 0; j < n; ++j) {
      cur += (a[j] - i) * (a[j] - i);
    }
    if (ans == -1 || cur < ans) ans = cur;
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::cout << solve(n) << std::endl;
  return 0;
}
