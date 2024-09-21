#include <cstdio>

const int MAXN = (int)1e5;

int a[MAXN];
int f[MAXN];

int solve(int n) {
  int res = 0;
  f[n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] >= a[i + 1]) {
      f[i] = f[i + 1] + 1;
    } else {
      f[i] = 0;
    }
    if (f[i] > res) res = f[i];
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  printf("%d\n", solve(n));
  return 0;
}
