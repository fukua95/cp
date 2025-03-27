#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

auto Solve(const std::vector<std::vector<int>> &edges, int root) -> bool {
  // lambda 不支持递归, std::function 支持.
  std::function<bool(int, int)> dfs = [&edges, &dfs](int u, int pa) -> bool {
    for (auto v : edges[u]) {
      if (v == pa) {
        continue;
      }
      if (!dfs(v, u)) {
        return true;
      }
    }
    return false;
  };
  return dfs(root, -1);
}

auto main() -> int {
  int n;
  int t;
  std::cin >> n >> t;
  std::vector<std::vector<int>> edges(n);
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    --u;
    --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  int root;
  for (int i = 0; i < t; ++i) {
    std::cin >> root;
    --root;
  }

  if (Solve(edges, root)) {
    std::cout << "Ron" << std::endl;
  } else {
    std::cout << "Hermione" << std::endl;
  }
}
