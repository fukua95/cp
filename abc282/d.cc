#include <cassert>
#include <iostream>
#include <map>
#include <vector>

void dfs(const std::vector<std::vector<int>> &edges, int u, std::vector<int> &colors) {
  for (auto &v : edges[u]) {
    if (colors[v] == -1) {
      colors[v] = colors[u] ^ 1;
      dfs(edges, v, colors);
    } else if (colors[v] >= 0) {
      if ((colors[v] ^ colors[u]) != 1) {
        colors[v] = -2;
      }
    }
  }
}

std::vector<int> color_nodes(const std::vector<std::vector<int>> &edges, int n) {
  int cur = 0;
  std::vector<int> colors(n, -1);
  for (int i = 0; i < n; ++i) {
    if (colors[i] == -1) {
      colors[i] = cur;
      dfs(edges, i, colors);
      cur += 2;
    }
  }
  return colors;
}

int64_t solve(const std::vector<std::vector<int>> &edges, int n, int m) {
  auto colors = color_nodes(edges, n);
  std::map<int, int> colors_count;
  for (int i = 0; i < n; ++i) {
    if (colors[i] == -2) {
      return 0;
    }
    colors_count[colors[i]]++;
  }
  int64_t ans = 0;
  for (auto [_, count] : colors_count) {
    ans += (int64_t)count * (n - count);
  }
  assert(ans % 2 == 0);
  ans = ans / 2 - m;
  return ans;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> edges(n);
  for (int i = 0, u, v; i < m; ++i) {
    std::cin >> u >> v;
    --u;
    --v;
    edges[u].emplace_back(v);
    edges[v].emplace_back(u);
  }

  std::cout << solve(edges, n, m) << std::endl;
  return 0;
}