#include <iostream>
#include <cmath>

using LL = long long;

LL gcd(LL a, LL b) {
  return b == 0 ? a : gcd(b, a % b);
}

int solve(LL a, LL b) {
  LL d = gcd(a, b);
  int res = 1;  // '1' 
  LL sqrt = std::sqrt(d + 0.5);
  for (int i = 2; i <= sqrt; ++i) {
    if (d % i == 0) {
      ++res;
      while (d % i == 0) d /= i;
    }
  }
  if (d > 1) ++res;
  return res;
}

int main() {
  LL a, b;
  std::cin >> a >> b;
  std::cout << solve(a, b) << std::endl;
  return 0;
}
