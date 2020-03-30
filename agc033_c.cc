#include <iostream>
#include <vector>
#include <cstdio>
#include <memory>

const int MAXN = 200000 + 1;

std::vector<std::vector<int>> tree(MAXN);

// The tree has n nodes
// currently at node u, pre from pre to u
// dis(1, u) = dis
// return value: first = farthest_node, second = farthest_dis
std::pair<int,int> FindFarthestDistance(int n, int u, int pre, int dis) {
  auto res = std::make_pair(u, dis);
  for (const auto& v : tree[u]) {
    if (v == pre) continue;
      auto a = FindFarthestDistance(n, v, u, dis + 1);
      if (a.second > res.second) {
        res = a;
      }
  }
  return res;
} 

int CalcTreeDiameter(int n) {
  auto a = FindFarthestDistance(n, 1, 0, 0);
  // printf("v = %d dis = %d\n", v, dis);
  auto diameter = FindFarthestDistance(n, a.first, 0, 0);
  // printf("t = %d diameter = %d\n", t, diameter);
  return diameter.second;
}

bool Solve(int n) {
  int diameter = CalcTreeDiameter(n);
  return (diameter + 1) % 3 != 2;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  if (Solve(n)) printf("First\n");
  else printf("Second\n");
  return 0;  
}
