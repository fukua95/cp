#include <iostream>

using namespace std;

int main() {
  int n, m, x, y;
  scanf("%d %d %d %d", &n, &m, &x, &y);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    x = max(x, a);
  }
  for (int i = 0, a; i < m; ++i) {
    scanf("%d", &a);
    y = min(y, a);
  }
  if (x < y) puts("No War");
  else puts("War");
  return 0;
}
