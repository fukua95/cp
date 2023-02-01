#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  if (m != n - 1) {
    std::cout << "No" << std::endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (graph[i].size() > 2) {
      std::cout << "No" << std::endl;
      return 0;
    }
  }

  std::vector<bool> reach(n, false);
  std::queue<int> que;
  reach[0] = true;
  que.push(0);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int v : graph[u]) {
      if (!reach[v]) {
        reach[v] = true;
        que.push(v);
      }
    }
  }
  for (int v : reach) {
    if (!v) {
      std::cout << "No" << std::endl;
      return 0;
    }
  }
  std::cout << "Yes" << std::endl;
  return 0;
}