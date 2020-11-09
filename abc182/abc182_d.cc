#include <iostream>

const int MAXN = (int)2e5 + 1;

int64_t pre[MAXN], pre_max[MAXN];

int main() {
  int n;
  pre[0] = pre_max[0] = 0;
  std::cin >> n;
  for (int i = 1, a; i <= n; ++i) {
    std::cin >> a;
    pre[i] = pre[i - 1] + a;
    pre_max[i] = std::max(pre_max[i - 1], pre[i]);
  }

  int64_t ans = 0, cur = 0;
  for (int i = 1; i <= n; ++i) {
    int64_t tmp = cur + pre_max[i];
    if (tmp > ans) ans = tmp;
    cur += pre[i];
  }
  std::cout << ans << std::endl;

  return 0;
} 