#include <cstdio>
#include <cmath>

int main() {
  int64_t a;
  scanf("%ld", &a);
  double ans = std::sqrt(a * (12800000 + a));
  printf("%.5f\n", ans);
  return 0;
}