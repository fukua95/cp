#include <cstdio>
#include <utility>
#include <algorithm>

const int MAXN = (int)1e5 + 1;

std::pair<int,int> a[MAXN];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    printf("%d ", a[i].second);
  }
  printf("\n");

  return 0;
}
