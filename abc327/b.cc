#include <bits/stdc++.h>

int main() {
  int64_t b;
  std::cin >> b;

  // 因为 16^16 > 1e18
  for (int i = 1; i < 16; ++i) {
    int64_t a = i;
    for (int j = 2; j <= i; ++j) {
      a *= i;
    }
    if (a == b) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  std::cout << "-1\n";
  return 0;
}
