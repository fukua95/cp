#include <iostream>
#include <utility>

using ll_t = long long;
const int MAXN = 300 + 1;
const int INF = (int)1e9 + 1;

int edge[MAXN][MAXN];
std::pair<int, int> f[MAXN][MAXN];
bool used[MAXN];

void dijkstra(int n, int l, int s) {
  for (int i = 1; i <= n; ++i) {
    used[i] = false;
    if (i == s) f[s][s] = std::make_pair(0, l);
    else f[s][i] = std::make_pair(INF, 0);
  }

  auto better = [](const std::pair<int, int> &x, const std::pair<int, int> &y) {
    if (x.first < y.first) return true;
    if (x.first == y.first && x.second > y.second) return true;
    return false;
  };

  while (true) {
    int v = -1;
    for (int u = 1; u <= n; ++u) {
      if (!used[u] && (v == -1 || better(f[s][u], f[s][v]))) v = u;
    }
    if (v == -1 || f[s][v].first >= INF) break;
    used[v] = true;
    for (int u = 1; u <= n; ++u) {
      if (u == v || edge[v][u] > l) continue;
      auto cur = f[s][v];
      if (cur.second - edge[v][u] < 0) {
        ++cur.first;
        cur.second = l;
      }
      cur.second -= edge[v][u];
      if (better(cur, f[s][u])) f[s][u] = cur;
    }
  }
}

void solve(int n, int l) {
  for (int s = 1; s <= n; ++s) {
    dijkstra(n, l, s);
  }
}

int main() {
  int n, m, l;
  std::cin >> n >> m >> l;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      edge[i][j] = edge[j][i] = INF;
    }
  }
  for (int i = 0, u, v, w; i < m; ++i) {
    std::cin >> u >> v >> w;
    edge[u][v] = edge[v][u] = w;
  }
  
  solve(n, l);
  
  int q;
  std::cin >> q;
  for (int i = 0, s, t; i < q; ++i) {
    std::cin >> s >> t;
    std::cout << (f[s][t].first >= INF ? -1 : f[s][t].first) << std::endl;
  }
  return 0;
}

