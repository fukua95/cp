#include <iostream>

int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int solve(int a, int b, int k) {
  int d = gcd(a, b);
  for (int i = d; i >= 1; --i) {
    if (d % i == 0) {
      --k;
      if (k == 0) {
        return i;
      }
    }
  }
  return -1;
}

int main() {
  int a, b, k;
  std::cin >> a >> b >> k;
  std::cout << solve(a, b, k) << std::endl;
  return 0;
}
