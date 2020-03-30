#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <assert.h>
#include <map>

const int MAXN = 51;

std::vector<int> edges[MAXN];
std::pair<int, int> rest[20];  // restrictions.
std::map<std::pair<int, int>, int> mark;
int pre[MAXN];

void dfs(int u) {
  for (const auto& v : edges[u]) {
    if (v == pre[u]) continue;
    pre[v] = u;
    dfs(v);
  }
}

void mark_edge(int u, int v, int tag) {
  if (u > v) std::swap(u, v);
  std::pair<int, int> edge = std::make_pair(u, v);
  if (!mark.count(edge)) {
    mark[edge] = 0;
  } 
  mark[edge] |= (1 << tag);
}

void mark_path(int u, int v, int tag) {
  pre[u] = -1;
  dfs(u);
  int node = v;
  while (node != u) {
    mark_edge(pre[node], node, tag);
    node = pre[node];
  }
}

// Calc the number of ways to paint the edges that satisfy all the m restrictions.
int64_t solve(int n, int m) {
  auto one_num = [](int x) -> int {
    int ans = 0;
    while (x > 0) {
      if (x & 1) ++ans;
      x >>= 1;
    }
    return ans;
  };

  for (int i = 0; i < m; ++i) {
    mark_path(rest[i].first, rest[i].second, i);
  }  
  int64_t ans = 1LL << (n - 1);  // 2 ^(n - 1).
  int rest_num = 1 << m;
  for (int i = 1; i < rest_num; ++i) {
    int flag = 1;
    if (one_num(i) % 2 == 1) flag = -1;
    int must_while_edges = 0;
    for (const auto& edge : mark) {
      int tag = edge.second;
      // std::cout << edge.first.first << " " << edge.first.second << " " << tag << std::endl;
      if (tag & i) ++must_while_edges;
    }
    assert(n - 1 >= must_while_edges);
    ans += flag * (1LL << (n - 1 - must_while_edges));
  }
  return ans;
}

int main() {
  int n, m;
  std::cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    edges[u].emplace_back(v);
    edges[v].emplace_back(u);
  }
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    std::cin >> rest[i].first >> rest[i].second;
  }
  std::cout << solve(n, m) << std::endl;
  return 0;
}

