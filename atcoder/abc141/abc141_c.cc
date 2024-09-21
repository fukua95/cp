#include <cstdio>

const int MAXN = (int)1e5;

int a[MAXN];


int main() {
  int n, k, q;
  scanf("%d %d %d", &n, &k, &q);
  for (int i = 0, cur; i < q; ++i) {
    scanf("%d", &cur);
    ++a[cur];
  }
  for (int i = 1; i <= n; ++i) {
    if (k + a[i] - q > 0) puts("Yes");
    else puts("No");
  }
  return 0;
}
