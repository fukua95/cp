#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> edges(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;
    edges[u].emplace_back(v);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    // dis[j] 表示节点j到节点i的距离.
    // n + 1 表示INF.
    std::vector<int> dis(n, n + 1);
    dis[i] = 0;
    std::queue<int> que;
    que.push(i);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (auto v : edges[u]) {
        if (dis[v] != n + 1) continue;
        dis[v] = dis[u] + 1;
        que.push(v);
      }
    }
    for (auto d : dis) {
      if (d > 1 && d < n + 1) ++ans;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}