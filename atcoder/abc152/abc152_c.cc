#include <iostream>

const int MAXN = (int)2e5;

int p[MAXN];

int solve(int n) {
  int cur_min = p[0];
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    if (p[i] < cur_min) {
      cur_min = p[i];
      ++ans;
    }
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> p[i];
  std::cout << solve(n) << std::endl;
  return 0;
}
