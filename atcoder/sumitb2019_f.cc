#include <iostream>

void solve(int64_t t1, int64_t t2, int64_t a1, int64_t a2, int64_t b1, int64_t b2) {
  if (t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2) {
    std::cout << "infinity" << std::endl;
    return;
  }
  int64_t ans = 0;
  int64_t X = t1 * a1 + t2 * a2 - t1 * b1 - t2 * b2;
  if (X < 0) {
    X = -X;
    std::swap(a1, b1);
    std::swap(a2, b2);
  }
  if (b1 - a1 > 0) {
    ans += t1 * (b1 - a1) / X;
  }
  int64_t Y = t1 * (b1 - a1 - b2 + a2);
  int64_t l, r;
  if (b2 - a2 > 0) {
    l = t1 * (b2 - a2) + Y;
    r = (t1 + t2) * (b2 - a2) + Y;
  } else {
    l = -(t1 + t2) * (a2 - b2) + Y;
    r = -t1 * (a2 - b2) + Y;
  }
  if (r > 0) {
    int64_t nr = (r + X - 1) / X;
    int64_t nl = l < 0 ? -1 : l / X;
    if (nr - nl - 1 > 0) ans += nr - nl - 1;
  }
  std::cout << ans << std::endl;
  return;
}

int main() {
  int64_t t1, t2, a1, a2, b1, b2;
  std::cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  solve(t1, t2, a1, a2, b1, b2);
  return 0;
}
