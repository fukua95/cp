#include <iostream>

const int MAXN = (int)2e6 + 3;
const int P = (int)1e9 + 7;

int64_t factorial[MAXN];


// Init array 'factorial'.
void init(int n) {
  factorial[0] = 1;
  for (int i = 1; i <= n; ++i) {
    factorial[i] = factorial[i - 1] * i % P;
  }
}

// Calc the inv of x (mod P).
int64_t inv(int64_t x) {
  auto power = [](int64_t a, int64_t b) -> int64_t {
    int64_t ans = 1;
    while (b > 0) {
      if (b & 1) ans = ans * a % P;
      a = a * a % P;
      b >>= 1;
    }
    return ans;
  };
  
  x %= P;
  return power(x, P - 2);
}

// Calc Comb(x, y) % P.
int64_t comb(int64_t x, int64_t y) {
  if (y == 0 || y == x) return 1;
  if (x < y) return 0;
  return factorial[x] * inv(factorial[y] * factorial[x - y]) % P;
}

int64_t solve(int r1, int r2, int c1, int c2) {
  int max_n = r2 + c2 + 2;
  init(max_n);
  int64_t ans = comb(r2 + c2 + 2, r2 + 1) - comb(c2 + r1 + 1, r1) - 
                comb(r2 + c1 + 1, r2 + 1) + comb(r1 + c1, r1);
  ans = (ans % P + P) % P;
  return ans;
}

int main() {
  int r1, c1, r2, c2;
  std::cin >> r1 >> c1 >> r2 >> c2;
  std::cout << solve(r1, r2, c1, c2) << std::endl;
  return 0;
}
