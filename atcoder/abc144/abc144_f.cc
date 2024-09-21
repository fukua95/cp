#include <cstdio>
#include <vector>
#include <algorithm>

const int MAXN = 600;
const double INF = MAXN;
std::vector<int> edges[MAXN];
double e[MAXN];

double calc(int n, int block) {
  e[n - 1] = 0;
  for (int u = n - 2; u >= 0; --u) {
    double sum = 0.0, max = 0.0;
    for (const auto &v : edges[u]) {
      sum += e[v];
      if (e[v] > max) max = e[v];
    }
    double num = (int)edges[u].size();
    if (u == block && num > 1) {
      --num;
      sum -= max;
    }
    e[u] = sum / num + 1.0;
  }
  return e[0];
}

double solve(int n) {
  double res = INF;
  for (int i = 0; i < n - 1; ++i) {
    double cur = calc(n, i);
    if (cur < res) res = cur;
  }
  return res;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0, u, v; i < m; ++i) {
    scanf("%d %d", &u, &v);
    edges[u - 1].emplace_back(v - 1);
  }
  printf("%.10lf\n", solve(n));
  return 0;
}
