#include <iostream>

const int P = (int)1e9 + 7;

int comb(int x, int y) {
  auto factorial = [](int n) -> int64_t {
    int64_t res = 1;
    for (int i = 2; i <= n; ++i) {
      res = res * i % P;
    }
    return res;
  };
  auto pow = [](int64_t x, int64_t y) -> int64_t {
    int64_t res = 1;
    while (y > 0) {
      if (y & 1) res = res * x % P;
      x = x * x % P;
      y >>= 1;
    }
    return res;
  };
  return factorial(x) * pow(factorial(x - y), P - 2) % 
         P * pow(factorial(y), P - 2) % P;
}

int solve(int n, int m) {
  if ((2 * m - n) % 3 != 0 || (2 * n - m) % 3 != 0) return 0;
  int x = (2 * m - n) / 3;
  int y = (2 * n - m) / 3;
  if (x < 0 || y < 0) return 0;
  return comb(x + y, x);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::cout << solve(n, m) << std::endl;
  return 0;
}
