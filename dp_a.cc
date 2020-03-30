#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = (int)1e5 + 5;
int h[MAXN];
int f[MAXN];

void solve(int n) {
  f[1] = 0;
  f[2] = abs(h[2] - h[1]);
  for (int i = 3; i <= n; ++i) {
    f[i] = min(f[i - 1] + abs(h[i - 1] - h[i]), f[i - 2] + abs(h[i - 2] - h[i]));
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", h + i);
  }
  solve(n);
  printf("%d\n", f[n]);
  return 0;
}
