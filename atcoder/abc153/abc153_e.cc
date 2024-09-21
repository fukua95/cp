#include <iostream>

const int MAXN = (int)1e3 + 1;
const int MAXH = (int)2e4 + 1;
const int INF = (int)2e8 + 1;

int f[MAXN][MAXH];
int profit[MAXN], cost[MAXN];

int solve(int h, int n) {
  int max_h = h + (int)1e4;
  for (int j = 0; j < max_h; ++j) {
    f[0][j] = INF;
  }
  f[0][0] = 0;
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < max_h; ++j) {
      f[i][j] = f[i - 1][j];
      if (j >= profit[i] && f[i][j] > f[i][j- profit[i]] + cost[i]) {
        f[i][j] = f[i][j - profit[i]] + cost[i];
      }
    }
  }
  int ans = f[n][h];
  for (int j = h + 1; j < max_h; ++j) {
    if (f[n][j] < ans)
      ans = f[n][j];
  }
  return ans;
}

int main() {
  int h, n;
  std::cin >> h >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> profit[i] >> cost[i];
  }
  std::cout << solve(h, n) << std::endl;
  return 0;
}
