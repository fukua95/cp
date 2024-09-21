#include <algorithm>
#include <iostream>
#include <vector>

// 找a中有多少个数x是l <= x <= r.
int solve(const std::vector<int>& a, int l, int r) {
  return std::upper_bound(a.begin(), a.end(), r) -
         std::lower_bound(a.begin(), a.end(), l);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> pos(n + 1);
  for (int i = 0, a; i < n; ++i) {
    std::cin >> a;
    pos[a].emplace_back(i);
  }

  int q;
  std::cin >> q;
  while (q--) {
    int l, r, val;
    std::cin >> l >> r >> val;
    std::cout << solve(pos[val], l - 1, r - 1) << std::endl;
  }
  return 0;
}