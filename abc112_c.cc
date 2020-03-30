#include <iostream>
#include <math.h>

using namespace std;

const int MAXN = 101;
int x[MAXN], y[MAXN], h[MAXN];

int check(int n, int a, int b, int cur) {
  int ans_h = -1, max_h = (int)1e9;
  for (int i = 0; i < n; ++i) {
    int tmp = abs(a - x[i]) + abs(b - y[i]);
    if (max(cur - tmp, 0) != h[i])
      return false;
  }
  return true;
}

void solve(int n) {
  int pos = -1;
  for (int i = 0; i < n; ++i) {
    if (h[i] != 0) {
      pos = i;
      break;
    }
  }
  for (int a = 0, cur; a <= 100; ++a) {
    for (int b = 0; b <= 100; ++b) {
      if (pos == -1) 
        cur = 1;
      else
        cur = abs(a - x[pos]) + abs(b - y[pos]) + h[pos];
      if (check(n, a, b, cur)) {
        printf("%d %d %d\n", a, b, cur);
        return ;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", x + i, y + i, h + i);
  }
  solve(n);
  return 0;
}
