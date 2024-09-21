#include <cstdio>
#include <algorithm>

const int MAXN = 12;
const int MAXM = (int)1e3 + 1;
const int INF = (int)1e8 + 1;

int cost[MAXM];    // cost[i] means cost of key i
int unlock_set[MAXM];  // unlock set of key i
int f[MAXM][1 << 12];  // f(i,j)表示前i个key,解锁集合j的最小花费

int solve(int n, int m) {
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      if (i == 0 && j == 0) f[i][j] = 0;
      else f[i][j] = INF;
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      if (f[i][j] == INF) continue;
      f[i + 1][j] = std::min(f[i + 1][j], f[i][j]);
      int &cur = f[i + 1][j | unlock_set[i + 1]];
      cur = std::min(cur, f[i][j] + cost[i + 1]);
      // printf("i=%d j=%d f=%d\n", i + 1, j | unlock_set[i + 1], cur);
    }
  }
  return f[m][(1 << n) - 1] != INF ? f[m][(1 << n) - 1] : -1;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int num, cur;
    scanf("%d %d", cost + i, &num);
    while (num--) {
      scanf("%d", &cur);
      unlock_set[i] |= (1 << (cur - 1));
    }
  }
  printf("%d\n", solve(n, m));
  return 0;
}

