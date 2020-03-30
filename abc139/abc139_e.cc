#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>

const int MAXN = 1000 * (1000 - 1) / 2;
const int INF = MAXN + 1;

int a[1000][1000 - 1];
int in_degree[MAXN];
std::vector<int> graph[MAXN];
int f[MAXN];

struct Hash {
  int tot;
  std::map<std::pair<int, int>, int> hash;
  
  void Build(int n) {
    tot = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        hash[std::make_pair(i, j)] = tot++;
      }
    }
  }
  int Calc(int i, int j) {
    if (i > j) std::swap(i, j);
    return hash[std::make_pair(i, j)];
  }
};
Hash hash;

void build_graph(int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      int p = hash.Calc(i, a[i][j - 1]);
      int v = hash.Calc(i, a[i][j]);
      graph[p].emplace_back(v);
      ++in_degree[v];
    }
  }  
}

void topo_sort(int n) {
  std::queue<int> que;
  for (int i = 0; i < hash.tot; ++i) {
    if (!in_degree[i]) {
      que.emplace(i);
      f[i] = 1;
    }
  }
  // printf("que_size = %d\n", (int)que.size());
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (const auto &v : graph[u]) {
      --in_degree[v];
      f[v] = std::max(f[v], f[u] + 1);
      if (!in_degree[v]) que.emplace(v);
    }
  }
}

int solve(int n) {
  int tot = 0;
  hash.Build(n);
  build_graph(n);
  for (int i = 0; i < hash.tot; ++i) f[i] = -1;
  topo_sort(n);

  int max = 0;
  for (int i = 0; i < hash.tot; ++i) {
    if (f[i] == -1) return -1;
    if (f[i] > max) max = f[i];
  }
  return max;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0, in; i < n; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      scanf("%d", &in);
      a[i][j] = in - 1;
    }
  }
  printf("%d\n", solve(n));
  return 0;
}
