#include <iostream>
#include <map>

const int MAXN = (int)2e5 + 1;

int a[MAXN];
int64_t sum[MAXN];

int64_t solve(int n, int k) {
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
  for (int i = 1; i <= n; ++i) sum[i] = sum[i] % k - i;
  
  // for (int i = 1; i <= n; ++i) std::cout << sum[i] << std::endl;

  std::map<int, int> rem;
  rem[0] = 1;
  
  int64_t res = 0;
  for (int i = 1, pre = 2 - k; i <= n; ++i, ++pre) {
    int tmp = 0;
    if (rem.find(sum[i]) != rem.end()) {
      res += rem[sum[i]];
      tmp += rem[sum[i]];
    }
    // std::cout << "i = " << i << " num = " << tmp << std::endl;
    ++rem[sum[i]];
    ++rem[sum[i] - k];
    if (pre >= 0) --rem[sum[pre]];
    if (pre > 0) --rem[sum[pre] - k];
  }
  return res;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::cout << solve(n, k) << std::endl;
  return 0;
}
