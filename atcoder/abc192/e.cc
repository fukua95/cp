#include <iostream>
#include <vector>
#include <queue>

using pli = std::pair<int64_t, int>;

struct Edge {
  Edge(int to, int t_p, int c) : to(to), t_point(t_p), cost(c) {}
  int to, t_point, cost;
};

int64_t earliest_time(const std::vector<std::vector<Edge>>& graph,
                      int n, int from, int to) {
  std::priority_queue<pli, std::vector<pli>, std::greater<pli>> que;
  std::vector<bool> used(n + 1, false);
  que.emplace(0, from);
  while (!que.empty()) {
    pli cur = que.top();
    que.pop();
    int64_t arrival = cur.first;
    int v = cur.second;
    if (v == to) return arrival;
    if (used[v]) continue;
    used[v] = true;
    for (const auto& edge : graph[v]) {
      if (used[edge.to]) continue;
      int64_t leave = (arrival + edge.t_point - 1) / edge.t_point * edge.t_point;
      que.emplace(leave + edge.cost, edge.to);
    }
  }
  return -1;
}

int main() {
  int n, m, from, to;
  std::cin >> n >> m >> from >> to;
  std::vector<std::vector<Edge>> graph(n + 1, std::vector<Edge>());
  for (int i = 0; i < m; ++i) {
    int u, v, t_p, c;
    std::cin >> u >> v >> c >> t_p;
    graph[u].emplace_back(v, t_p, c);
    graph[v].emplace_back(u, t_p, c);
  }
  std::cout << earliest_time(graph, n, from, to) << std::endl;
  return 0;
}