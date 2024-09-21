#include <iostream>
#include <vector>
#include <utility>

using pii = std::pair<int, int>;
const int MAXN = (int)1e5;

std::vector<pii> edges[MAXN];
int edge_color[MAXN];

void dfs(int u, int par, int par_edge_color) {
  int cur_color = 1;
  for (const auto &cur : edges[u]) {
    int v = cur.first;
    int edge_index = cur.second;
    if (v == par) continue;
    if (cur_color == par_edge_color) ++cur_color;
    edge_color[edge_index] = cur_color++;
    dfs(v, u, edge_color[edge_index]);
  }
}

void solve(int n) {
  int color_num = 0;
  int root = 0;
  for (int i = 0; i < n; ++i) {
    if (edges[i].size() > color_num) {
      color_num = edges[i].size();
      root = i;
    }
  }
  dfs(root, -1, 0);

  std::cout << color_num << std::endl;
  for (int i = 0; i < n - 1; ++i) {
    std::cout << edge_color[i] << std::endl;
  }
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0, u, v; i < n - 1; ++i) {
    std::cin >> u >> v;
    --u;
    --v;
    edges[u].emplace_back(v, i);
    edges[v].emplace_back(u, i);
  }
  solve(n);
  return 0;
}
