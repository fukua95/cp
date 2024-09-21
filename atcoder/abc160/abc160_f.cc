#include <iostream>
#include <algorithm>
#include <vector>

const int MAXN = (int)2e5;
const int P = (int)1e9 + 7;

std::vector<int> edges[MAXN];
int size[MAXN];     // size of subtree(i).
int64_t f[MAXN];    // subtree(i), 先选i, 的方案数.
int64_t ans[MAXN];  // 整棵树, 先选i, 的方案数.
int64_t factorial[MAXN];

// inv of P.
int64_t inv(int64_t x) {
  int y = P - 2;
  int64_t ans = 1;
  while (y > 0) {
    if (y & 1) ans = ans * x % P;
    x = x * x % P;
    y >>= 1;
  }
  return ans;
}

// Calc C(x, y).
int64_t comb(int x, int y) {
  if (y == 0 || y == x) return 1;
  return factorial[x] * inv(factorial[y] * factorial[x - y] % P) % P;
}

void calc_f(int u, int pa) {
  size[u] = 0;
  f[u] = 1; 
  for (const auto& v : edges[u]) {
    if (v == pa) continue;
    calc_f(v, u);
    size[u] += size[v];
    f[u] = f[u] * comb(size[u], size[v]) % P * f[v] % P;
  }
  ++size[u];
}

// ans[v] = (size[v] / (n - size[v])) * ans[u].
void calc_ans(int u, int pa, int n) {
  for (const auto& v : edges[u]) {
    if (v == pa) continue;
    ans[v] = ans[u] * size[v] % P * inv(n - size[v]) % P;
    calc_ans(v, u, n);
  }
}

void solve(int n) {
  factorial[0] = 1;
  for (int i = 1; i <= n; ++i) {
    factorial[i] = factorial[i - 1] * i % P;
  }

  calc_f(0, -1);
  ans[0] = f[0];
  calc_ans(0, -1, n);
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    --u, --v;
    edges[u].emplace_back(v);
    edges[v].emplace_back(u);
  }
  solve(n);
  for (int i = 0; i < n; ++i) std::cout << ans[i] << std::endl;

  return 0;
}
