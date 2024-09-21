#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void calc_divisor(int64_t n, std::vector<int64_t>* divisor) {
  if (n != 1) divisor->emplace_back(n);
  int64_t sqrt = std::sqrt(n + 0.5);
  for (int64_t i = 2; i <= sqrt; ++i) {
    if (n % i == 0) {
      divisor->emplace_back(i);
      int64_t j = n / i;
      if (j != i) divisor->emplace_back(j);
    }
  }
}

int solve(int64_t n) {
  std::vector<int64_t> divisor;
  calc_divisor(n - 1, &divisor);
  std::vector<int64_t> ans(divisor);
  divisor.clear();
  calc_divisor(n, &divisor);
  for (const auto& d : divisor) {
    int64_t cur = n / d;
    while (cur % d == 0) cur /= d;
    if (cur % d == 1) ans.emplace_back(d);
  }
  std::sort(ans.begin(), ans.end());
  return (int)(std::unique(ans.begin(), ans.end()) - ans.begin());
}

int main() {
  int64_t n;
  std::cin >> n;
  std::cout << solve(n) << std::endl;
  return 0;
}
