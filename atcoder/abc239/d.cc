#include <iostream>

bool is_prime(int x) {
  for (int i = 2; i < x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  bool ans = false;
  for (int i = a; i <= b; ++i) {
    bool can = false;
    for (int j = c; j <= d; ++j) {
      if (is_prime(i + j)) {
        can = true;
        break;
      }
    }
    if (!can) {
      ans = true;
      break;
    }
  }
  if (ans) std::cout << "Takahashi" << std::endl;
  else std::cout << "Aoki" << std::endl;
  return 0;
}