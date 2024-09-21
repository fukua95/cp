#include <iostream>
#include <utility>

const int MAXN = (int)1e5 + 3;
int64_t ans[MAXN];
std::pair<int,int> edge[MAXN];
int fa[MAXN];
int num[MAXN];

int find(int u) {
  if (fa[u] == u)
    return u;
  fa[u] = find(fa[u]);
  num[fa[u]] += num[u];
  num[u] = 0;
  return fa[u];
}

void union_set(int u, int v) {
  fa[u] = v;
  num[v] += num[u];
  num[u] = 0;
}

void solve(int n, int m) {
  ans[m + 1] = (int64_t)n * (n - 1) / 2;
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    num[i] = 1;
  }
  for (int i = m; i > 0; --i) {
    int u = edge[i].first;
    int v = edge[i].second;
    int fau = find(u);
    int fav = find(v);
    if (fau == fav)
      ans[i] = ans[i + 1];
    else {
      ans[i] = ans[i + 1] - (int64_t)num[fau] * num[fav];
      union_set(fau, fav);
    }
  }  
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i) 
    std::cin >> edge[i].first >> edge[i].second;
  solve(n, m);
  for (int i = 1; i <= m; ++i) 
    std::cout << ans[i] << std::endl;
  return 0;
}

