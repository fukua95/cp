#include <iostream>

int digits(int x) {
  int res = 1;
  while (x >= 10) {
    ++res;
    x /= 10;
  }
  return res;
}

int solve(int64_t a, int64_t b, int64_t x) {
  int l = 0, r = (int)1e9;
  if (a * r + b * digits(r) <= x) return r;
  while (r - l > 1) {
    int mid = (r + l) >> 1;
    if (a * mid + b * digits(mid) <= x) l = mid;
    else r = mid;
  }
  return l;
}

int main() {
  int64_t a, b, x;
  std::cin >> a >> b >> x;
  std::cout << solve(a, b, x) << std::endl;
  return 0;
}
