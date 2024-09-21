#include <bits/stdc++.h>

auto main() -> int {
  char a, b, c;
  std::cin >> a >> b >> c;
  if (a != b) {
    std::cout << "A\n";
  } else if (b != c) {
    std::cout << "C\n";
  } else {
    std::cout << "B\n";
  }
  return 0;
}