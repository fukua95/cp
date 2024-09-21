#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

void solve(int n, int x, int y) {
  std::vector<int> count(n, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int dis;
      if (j <= x || i >= y) dis = j - i;
      else if (i <= x) dis = x - i + std::min(j - x, std::abs(y - j) + 1);
      else if (j <= y) dis = std::min(j - i, i - x + 1 + y - j);
      else dis = j - y + std::min(y - i, i - x + 1);
      ++count[dis];
    }
  }
  for (int i = 1; i < n; ++i) std::cout << count[i] << std::endl;
}

int main() {
  int n, x, y;
  std::cin >> n >> x >> y;
  solve(n, x, y);
  return 0;
}
