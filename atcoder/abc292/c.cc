#include <iostream>

// 计算有多少(a,b)满足a*b=x
// 枚举a,复杂度O(sqrt(x))
int64_t mul_count(int x) {
  int64_t ans = 0;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      if ((x / i) == i)
        ans += 1;
      else
        ans += 2;
    }
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  int64_t ans = 0;
  for (int i = 1; i < n; ++i) {
    ans += mul_count(i) * mul_count(n - i);
  }
  std::cout << ans << std::endl;
  return 0;
}