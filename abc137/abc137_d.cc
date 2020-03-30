#include <cstdio>
#include <vector>
#include <queue>

const int MAXN = (int)1e5;

std::vector<int> a[MAXN];

int solve(int n, int m) {
  int res = 0;
  std::priority_queue<int> pq;
  for (int i = m - 1; i >= 0; --i) {
    for (const auto &cur : a[i]) {
      pq.push(cur);
    }
    if (!pq.empty()) {
      res += pq.top();
      pq.pop();
    }
  }
  return res;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    if (m - u < 0) continue;
    a[m - u].emplace_back(v);
  }
  printf("%d\n", solve(n, m));
  return 0;
}
