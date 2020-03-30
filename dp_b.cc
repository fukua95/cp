#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = (int)1e5 + 5;
const int INF = (int)1e9 + 1;
int h[MAXN];
int f[MAXN];

void solve(int n, int k) {
  f[1] = 0;
  for (int i = 2; i <= n; ++i) {
    f[i] = INF;
    for (int j = i - 1; j >= i - k && j >= 1; --j)
    f[i] = min(f[i], f[j] + abs(h[j] - h[i]));
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", h + i);
  }
  solve(n, k);
  printf("%d\n", f[n]);
  return 0;
}
