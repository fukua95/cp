#include <bits/stdc++.h>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  bool can = false;

  if (b <= c) {
    can = a < b || a > c;
  } else {
    can = a > c && a < b;
  }

  std::cout << (can ? "Yes" : "No") << std::endl;
  return 0;
}