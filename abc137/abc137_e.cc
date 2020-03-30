#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using pii = std::pair<int, int>; 
const int MAXN = 2500;
const int INF = (int)1e9;

std::vector<pii> edge[MAXN];  // pii = (to, cost)
std::vector<int> reverse_edge[MAXN];
int min_dis[MAXN];
bool can_reach_dest[MAXN];

void dfs_reverse_graph(int u) {
  for (const auto &v : reverse_edge[u]) {
    if (can_reach_dest[v]) continue;
    can_reach_dest[v] = true;
    dfs_reverse_graph(v);
  }
}

void shortest_path(int s, int n) {
  for (int i = 0; i < n; ++i) min_dis[i] = INF;
  min_dis[s] = 0;
  for (int num = 1; num < n; ++num) {
    for (int i = 0; i < n; ++i) {
      if (min_dis[i] == INF) continue;
      for (const auto &cur : edge[i]) {
        int to = cur.first, cost = cur.second;
        if (min_dis[to] > min_dis[i] + cost) {
          min_dis[to] = min_dis[i] + cost;
        }
      }
    }
  }
}

bool has_min_dis(int n) {
  for (int i = 0; i < n; ++i) {
    if (min_dis[i] == INF) continue;
    for (const auto &cur : edge[i]) {
      int to = cur.first, cost = cur.second;
      if (min_dis[to] == INF) continue;
      if (min_dis[to] > min_dis[i] + cost && can_reach_dest[to]) {
        // std::cout << "u = " << i << " v = " << to << std::endl;
        return false;
      }
    }
  }
  return true;
}

int solve(int n) {
  for (int i = 0; i < n; ++i) can_reach_dest[i] = false;
  can_reach_dest[n - 1] = true;
  dfs_reverse_graph(n - 1);

  shortest_path(0, n);

  // std::cout << -min_dis[n - 1] << std::endl;

  if (has_min_dis(n)) return std::max(0, -min_dis[n - 1]);
  else return -1;
}

int main() {
  int n, m, p;
  std::cin >> n >> m >> p;
  for (int i = 0, u, v, w; i < m; ++i) {
    std::cin >> u >> v >> w;
    --u;
    --v;
    w = p - w;
    edge[u].emplace_back(v, w);
    reverse_edge[v].emplace_back(u);
  }
  std::cout << solve(n) << std::endl;
  return 0;
}
