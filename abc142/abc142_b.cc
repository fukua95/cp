#include <cstdio>

int main() {
  int n, m, ans = 0;
  scanf("%d %d", &n, &m);
  while (n--) {
    int cur;
    scanf("%d", &cur);
    if (cur >= m) ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
