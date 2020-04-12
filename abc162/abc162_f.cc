#include <iostream>
#include <map>
#include <cstdio>

const int MAXN = (int)2e5 + 1;
const int64_t INF = (int64_t)1e17;
int a[MAXN];
std::map<int, int64_t> f[MAXN];

int get_min(int i, int n) {
  if (n % 2 == 1) return (i - 1) / 2;
  return i / 2;
}

int get_max(int i) {
  return (i + 1) / 2;
}

int64_t solve(int n) {
  for (int i = 1; i <= n; ++i) {
    int min = get_min(i, n);
    int max = get_max(i);
    for (int j = min; j <= max; ++j) {
      f[i][j] = -INF;
    }
  }
  f[1][0] = 0;
  f[1][1] = a[1];
  f[2][0] = 0;
  f[2][1] = std::max(a[1], a[2]);
  for (int i = 3; i <= n; ++i) {
    int i_min = get_min(i, n);
    int i_max = get_max(i);
    for (int j = i_min; j <= i_max; ++j) {
      if (get_min(i - 1, n) <= j && j <= get_max(i - 1)) 
        f[i][j] = f[i - 1][j];
      if (i > 2 && get_min(i - 2, n) <= j - 1 && j - 1 <= get_max(i - 2)) {
        int64_t cur = f[i - 2][j - 1] + a[i];
        if (cur > f[i][j]) f[i][j] = cur;
      }
      // printf("i = %d j = %d f = %lld\n", i, j, (long long)f[i][j]);
    }
  }
  return f[n][n / 2];
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::cout << solve(n) << std::endl;
  return 0;
}
