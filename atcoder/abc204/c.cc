#include <iostream>
#include <vector>

int dfs(int cur, const std::vector<std::vector<int>>& graph, 
        std::vector<bool>& visited, int n) {
  if (visited[cur]) return 0;
  int ans = 1;
  visited[cur] = true;
  for (const auto& v: graph[cur]) {
    if (visited[v]) continue;
    ans += dfs(v, graph, visited, n);
  }
  return ans;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  for (int i = 0, u, v; i < m;++i) {
    std::cin >> u >> v;
    --u;
    --v;
    graph[u].emplace_back(v);
  }

  int ans = 0;
  for (int s = 0; s < n; ++s) {
    std::vector<bool> visited(n, false);
    ans += dfs(s, graph, visited, n);
  }
  std::cout << ans << std::endl;

  return 0;
}