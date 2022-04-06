#include <iostream>
#include <vector>

int query(const std::vector<int64_t>& f, int64_t limit) {
  int len = f.size();
  if (f[len - 1] <= limit) {
    return -1;
  }
  int l = 0, r = len - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (f[mid] > limit) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return r;
}

int main() {
  int n, cost_limit;
  std::cin >> n >> cost_limit;
  // gain[i]表示单个队友的花费为i时，最大收益.
  std::vector<int64_t> gain(cost_limit + 1, 0);
  for (int i = 0; i < n; ++i) {
    int c, d, h;
    std::cin >> c >> d >> h;
    int64_t val = (int64_t)d * h;
    if (gain[c] < val) {
      gain[c] = val;
    }
  }
  // f[i]表示花i的cost，能获得的最大收益,即(i / c) * d * h的最大值.
  std::vector<int64_t> f(cost_limit + 1, 0);
  // 1 + 1/2 + 1/3 + 1/4 + ... + 1/n = O(logn)
  for (int i = 1; i <= cost_limit; ++i) {
    if (gain[i] == 0) continue;
    for (int j = i; j <= cost_limit; j += i) {
      int64_t val = (j / i) * gain[i];
      if (f[j] < val) {
        f[j] = val;
      }
    }
  }
  /*
  for (int i = 1; i <= cost_limit; ++i) {
    std::cout << "i = " << i << " f = " << f[i] << std::endl;
  }
  */

  for (int i = 1; i <= cost_limit; ++i) {
    if (f[i - 1] > f[i]) {
      f[i] = f[i - 1];
    }
  }
  // 现在f是一个单调非递减的数组，对于每一个查询，二分得到答案.
  int q;
  std::cin >> q;
  while (q--) {
    int64_t d, h;
    std::cin >> d >> h;
    h *= d;
    std::cout << query(f, h) << std::endl;
  }
  return 0;
}