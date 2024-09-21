#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void dfs(int pos, int limit, std::vector<int> a) {
  if (pos == limit) {
    for (const auto& x : a) std::cout << (char)('a' + x);
    std::cout << std::endl;
    return;
  }
  int ma = 0;
  for (const auto& x : a) {
    if (x > ma) ma = x;
  }
  ++ma;
  for (int i = 0; i <= pos && i <= ma; ++i) {
    std::vector<int> cur(a);
    cur.emplace_back(i);
    dfs(pos + 1, limit, cur);
  }
}

void solve(int n) {
  std::vector<int> a;
  dfs(0, n, a);
}

int main() {
  int n;
  std::cin >> n;
  solve(n);
  return 0;
}
