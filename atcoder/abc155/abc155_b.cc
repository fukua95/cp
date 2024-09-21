#include <iostream>

int main() {
  int n;
  bool can = true;
  std::cin >> n;
  for (int i = 0, a; i < n; ++i) {
    std::cin >> a;
    if (a % 2 == 0 && a % 3 != 0 && a % 5 != 0) can = false;
  }
  if (can) std::cout << "APPROVED" << std::endl;
  else std::cout << "DENIED" << std::endl;
  return 0;
}
