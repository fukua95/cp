#include <iostream>
#include <map>

const int P = 998244353;

// calc x ^ y % P.
int64_t pow(int64_t x, int y) {
  int64_t ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % P;
    y >>= 1;
    x = x * x % P;
  }
  return ans;
}

int64_t inv(int64_t x) { return pow(x, P - 2); }

int64_t calc(int64_t n, std::map<int64_t, int> &f, int inv5) {
  if (n == 1) return 1;
  if (f.find(n) != f.end()) return f[n];

  int64_t ans = 0;
  for (int i = 2; i <= 6; ++i) {
    if (n % i != 0) continue;
    ans = (ans + calc(n / i, f, inv5)) % P;
  }
  ans = ans * inv5 % P;
  f[n] = ans;
  return ans;
}

int main() {
  int64_t n;
  std::cin >> n;

  int inv5 = inv(5);
  std::map<int64_t, int> f;

  std::cout << calc(n, f, inv5) << std::endl;
  return 0;
}