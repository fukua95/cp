#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;

const int MAXN = 200000 + 5;

int a[MAXN];

LL solve(int n) {
  for (int i = 1; i <= n; ++i) {
    a[i] -= i;
  }
  sort(a + 1, a + n + 1);
  int mid = a[(n + 1) / 2];
  LL res = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] < mid) 
      res += mid - a[i];
    else
      res += a[i] - mid;
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  printf("%lld\n", solve(n));
  return 0;
}
