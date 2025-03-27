// problem:
// 给出一棵树，每次操作可以裁剪一个叶子节点，问最少需要多少次操作，使得树的所有叶子的深度相同.
//
// solution:
// 定义 depths(i) 表示节点 i 的深度
//     subtree_depths(i) 表示以 i 为根的子树，的叶子的最大深度
// 枚举最终的树的叶子深度 d: 0 -> n - 1,
// 对于 d: 节点 i 不用被裁剪 iff depths(i) <= d <= subtree_depths(i),
// 问题等价于：有 n 个区间 [depths, subtree_depths]，找到在最多的区间内的 d.
// 只需要区间 l + 1, (r + 1) - 1, 求前缀和，再遍历找到值最大的位置.

#include <functional>
#include <iostream>
#include <vector>

int solve(int n, const std::vector<std::vector<int>> &edges) {
  std::vector<int> depths(n, 0);
  std::vector<int> subtree_depths(n, 0);

  std::function<void(int, int)> dfs = [&](int u, int p) {
    subtree_depths[u] = depths[u];
    for (auto v : edges[u]) {
      if (v == p) continue;
      depths[v] = depths[u] + 1;
      dfs(v, u);
      subtree_depths[u] = std::max(subtree_depths[u], subtree_depths[v]);
    }
  };
  dfs(0, -1);

  std::vector<int> sum(n + 1, 0);
  for (int i = 0; i < n; i++) {
    sum[depths[i]]++;
    sum[subtree_depths[i] + 1]--;
  }

  int res = 0;
  for (int i = 1; i < n; i++) {
    sum[i] += sum[i - 1];
    if (sum[i] > sum[res]) {
      res = i;
    }
  }
  return n - sum[res];
}

int main() {
  int t, n;
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    std::vector<std::vector<int>> edges(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--;
      v--;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    std::cout << solve(n, edges) << std::endl;
  }
  return 0;
}