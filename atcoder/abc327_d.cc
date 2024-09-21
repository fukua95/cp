#include <bits/stdc++.h>

void dfs(const std::vector<std::vector<int>> &graph, std::vector<int> &color, int u, bool *bipartite) {
  for (auto v : graph[u]) {
    if (color[v] == -1) {
      color[v] = color[u] ^ 1;
      dfs(graph, color, v, bipartite);
    } else if (color[v] == color[u]) {
      *bipartite = false;
    }
  }
}

bool is_bipartite_graph(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  bool bipartite = true;
  std::vector<int> color(n, -1);
  for (int i = 0; i < n; ++i) {
    if (color[i] == -1) {
      color[i] = 0;
      dfs(graph, color, i, &bipartite);
    }
  }
  return bipartite;
}

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> graph(n);
  std::vector<int> edge_s(m), edge_t(m);
  for (int i = 0; i < m; ++i) std::cin >> edge_s[i];
  for (int i = 0; i < m; ++i) std::cin >> edge_t[i];
  for (int i = 0; i < m; ++i) {
    int s = edge_s[i] - 1, t = edge_t[i] - 1;
    graph[s].push_back(t);
    graph[t].push_back(s);
  }

  std::cout << (is_bipartite_graph(graph) ? "Yes" : "No") << std::endl;

  return 0;
}