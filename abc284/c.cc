#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>> &edges, std::vector<bool> &visited, int u) {
  for (auto v : edges[u]) {
    if (visited[v]) continue;
    visited[v] = true;
    dfs(edges, visited, v);
  }
}

int count_connected_component(const std::vector<std::vector<int>> &edges, int n) {
  int ans = 0;
  std::vector<bool> visited(n, false);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      ++ans;
      visited[i] = true;
      dfs(edges, visited, i);
    }
  }
  return ans;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> edges(n);
  for (int i = 0, u, v; i < m; ++i) {
    std::cin >> u >> v;
    --u;
    --v;
    edges[u].emplace_back(v);
    edges[v].emplace_back(u);
  }
  std::cout << count_connected_component(edges, n) << std::endl;
  return 0;
}