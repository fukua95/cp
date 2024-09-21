#include <iostream>
#include <utility>
#include <algorithm>

#define l first
#define r second

const int MAXN = (int)1e5;

std::pair<int, int> a[MAXN];

int solve(int n) {
  std::sort(a, a + n, [](const auto& u, const auto& v) {
    return u.r < v.r; 
  });
  int ans = 1;
  int cur_r = a[0].r;
  for (int i = 1; i < n; ++i) {
    if (a[i].l < cur_r) continue;
    ++ans;
    cur_r = a[i].r;
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0, u, v; i < n; ++i) {
    std::cin >> u >> v;
    a[i].l = u - v;
    a[i].r = u + v;
  }
  std::cout << solve(n) << std::endl;
  return 0;
}
