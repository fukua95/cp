#include <iostream>

int main() {
  int n, m, k;
  std::cin >> n >> k >> m;
  int res = m * n;
  for (int i = 1; i < n; ++i) {
    int in;
    std::cin >> in;
    res -= in;
  }
  if (res < 0) res = 0;
  else if (res > k) res = -1;
  std::cout << res << std::endl;
  return 0;
}
