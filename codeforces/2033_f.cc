// problem:
// fib(1) = fib(2) = 1.
// fib(n) = fib(n - 1) + fib(n - 2), n >= 3.
// 定义 G(n, k) = 可以被 k 整除的第 n 个 fib-number 的索引.
// 给定 n, k, 计算 G(n, k).
//
// solution:
// 数论有一个 Pisano period: 对于任意一个数 n, fib(i) % n 组成的序列是一个周期性重复的序列，并且周期 <= 6n.
// 根据这个性质，我们:
// 1. 对于 k, 暴力计算周期长度 period_len，长度一定 <= 6k, 所以复杂度 O(k).
// 2. 计算每个周期内，可以被 k 整除的数量 period_count.
// remaining = n % period_count.
// 1. remaining > 0:
//    ans = n / period_count * period_len + 遍历周期，找到第 remaining 个被 k 整除的数对应的索引.
// 2. remaining == 0:
//    ans = (n / period_count - 1) * period_len + 遍历周期，找到第 period_count 个被 k 整除的数对应的索引.

#include <iostream>
#include <vector>

int solve(int64_t n, int k) {
  const int P = (int)1e9 + 7;
  if (k == 1) {
    return n % P;
  }

  std::vector<int> fib(6 * k + 3);  // 最多需要遍历到 6k + 2.
  fib[1] = fib[2] = 1;
  int period_len = 2;
  while (true) {
    period_len++;
    fib[period_len] = (fib[period_len - 1] + fib[period_len - 2]) % k;
    if (fib[period_len] == 1 && fib[period_len - 1] == 1) {  // fib(1) = 1, fib(2) = 1，找到周期.
      period_len -= 2;
      break;
    }
  }

  int period_count = 0;
  int last = 0;
  for (int i = 1; i <= period_len; i++) {
    if (fib[i] == 0) {
      ++period_count;
      last = i;
    }
  }

  // 特殊处理整除的场景.
  int remaining = n % period_count;
  if (remaining == 0) {
    return (((n / period_count - 1) % P) * period_len + last) % P;
  }

  for (int i = 1; i <= period_len; i++) {
    if (fib[i] == 0) {
      --remaining;
      if (remaining == 0) {
        return (((n / period_count) % P) * period_len + i) % P;
      }
    }
  }
  return 0;  // unreachable
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int64_t n;
    int k;
    std::cin >> n >> k;
    std::cout << solve(n, k) << std::endl;
  }
  return 0;
}