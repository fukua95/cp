#include <cstdio>
#include <set>
#include <cmath>

using LL = long long;

std::multiset<int> tree;

LL solve(int n, int m) {
  while (m--) {
    auto iter = tree.begin();
    int cur = *iter;
    if (cur == 0) break;
    cur = std::ceil(cur / 2.0);
    tree.erase(iter);
    tree.insert(cur);
  }
  
  LL res = 0;
  for (const auto &cur : tree) {
    res -= cur;  // res += (-cur)
  }
  return res;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0, in; i < n; ++i) {
    scanf("%d", &in);
    tree.insert(-in);
  }
  printf("%lld\n", solve(n, m));
  return 0;
}
