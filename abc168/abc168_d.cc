#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> edges;
std::vector<int> dis;
std::vector<int> pre;

void bfs(int n) {
  dis[1] = 0;
  std::queue<int> que;
  que.push(1);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (const auto& v : edges[u]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        pre[v] = u;
        que.push(v);
      }
    }
  }
}

bool solve(int n) {
  bfs(n);
  for (int i = 2; i <= n; ++i) {
    if (dis[i] >= n)
      return false;
  }
  return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  
  dis = std::vector<int>(n + 1, n + 1);
  pre = std::vector<int>(n + 1, -1);
  edges = std::vector<std::vector<int>>(n + 1);
  
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    edges[u].emplace_back(v);
    edges[v].emplace_back(u);
  }
  if (solve(n)) {
    std::cout << "Yes" << std::endl;
    for (int i = 2; i <= n; ++i) 
      std::cout << pre[i] << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}
