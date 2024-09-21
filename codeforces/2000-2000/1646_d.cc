#include <iostream>
#include <vector>

using pii = std::pair<int, int>;

// c++ std::pair没有重载+运算符，需要自己实现.
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
  return std::make_pair(l.first + r.first, l.second + r.second);
}

pii better(pii x, pii y) {
  if (x.first > y.first || (x.first == y.first && x.second < y.second))
    return x;
  return y;
}

// dp
void calc_f(const std::vector<std::vector<int>>& edges, int u, int pa,
            std::vector<std::vector<pii>>& f) {
  f[u][0] = std::make_pair(0, 1);
  f[u][1] = std::make_pair(1, edges[u].size());
  for (const auto& v : edges[u]) {
    if (v == pa) continue;
    calc_f(edges, v, u, f);
    f[u][1] = f[u][1] + f[v][0];
    f[u][0] = f[u][0] + better(f[v][0], f[v][1]);
  }
}

// 根据f倒推每个节点的weight.
void calc_weight(const std::vector<std::vector<int>>& edges,
                 const std::vector<std::vector<pii>>& f, int u, int u_selected,
                 int pa, std::vector<int>& weights) {
  weights[u] = u_selected == 1 ? edges[u].size() : 1;
  for (const auto& v : edges[u]) {
    if (v == pa) continue;
    if (u_selected == 1 || (better(f[v][0], f[v][1]) == f[v][0])) {
      calc_weight(edges, f, v, 0, u, weights);
    } else {
      calc_weight(edges, f, v, 1, u, weights);
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> edges(n);
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    --u;
    --v;
    edges[u].emplace_back(v);
    edges[v].emplace_back(u);
  }

  // f[i][0]表示以i为root的子树，如果i不选，(最多能选多少个节点,子树的weight和的最小值)
  // f[i][1]表示以i为root的子树，如果i选了，(最多能选多少个节点,子树的weight和的最小值)
  std::vector<std::vector<pii>> f(n, std::vector<pii>(2));
  calc_f(edges, 0, -1, f);

  int root_selected = better(f[0][0], f[0][1]) == f[0][0] ? 0 : 1;
  int max_selected_count = f[0][root_selected].first;
  int weight_sum = f[0][root_selected].second;
  // 特殊处理只有2个节点的情况.
  if (n == 2) ++max_selected_count;

  std::vector<int> weights(n);
  calc_weight(edges, f, 0, root_selected, -1, weights);

  // output
  std::cout << max_selected_count << " " << weight_sum << std::endl;
  for (const auto& w : weights) {
    std::cout << w << " ";
  }
  std::cout << std::endl;

  return 0;
}