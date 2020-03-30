#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using ll_t = long long;
const int MAXN = 500;

int a[MAXN];
std::vector<int> divisor;

void get_divisor(int x) {
  int sqrt = std::sqrt(x + 0.5);
  for (int i = 1; i <= sqrt; ++i) {
    if (x % i == 0) {
      divisor.emplace_back(i);
      if (x / i != i) divisor.emplace_back(x / i);
    }
  }
  std::sort(divisor.begin(), divisor.end(), [](int a, int b) {
    return a > b;
  });
}

int calc_op_num(int d, int n) {
  std::vector<int> remainder;
  ll_t sum = 0;
  for (int i = 0; i < n; ++i) {
    int r = a[i] % d;
    if (r == 0) continue;
    remainder.emplace_back(r);
    sum += r;
  }
  int zero_num = (int)remainder.size() - sum / d;
  std::sort(remainder.begin(), remainder.end());
  int res = 0;
  for (int i = 0; i < zero_num; ++i) {
    res += remainder[i];
  }
  return res;
}

int solve(int n, int m) {
  int sum = 0;
  for (int i = 0; i < n; ++i) sum += a[i];
  get_divisor(sum);

  for (const auto &d : divisor) {
    if (calc_op_num(d, n) <= m) return d;
  }
  return -1;  // It will never happen
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::cout << solve(n, m) << std::endl;
  return 0;
}
