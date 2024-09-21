#include <cstdio>
#include <vector>

const int MAXN = (int)2e5 + 1;

std::vector<int> tree[MAXN];
int dfs_seq[MAXN];
int dfs_seq_cur;
int size[MAXN];
int f[MAXN];

void dfs(int p, int u) {
  size[u] = 1;
  dfs_seq[u] = ++dfs_seq_cur;
  for (const auto &v : tree[u]) {
    if (v == p) continue;
    dfs(u, v);
    size[u] += size[v];
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  dfs_seq_cur = 0;
  dfs(-1, 1);
  for (int i = 0, x, u; i < q; ++i) {
    scanf("%d %d", &u, &x);
    f[dfs_seq[u]] += x;
    f[dfs_seq[u] + size[u]] -= x;
  }
  for (int i = 2; i <= n; ++i) {
    f[i] += f[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", f[dfs_seq[i]]);
  }
  return 0;
}
