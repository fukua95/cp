#include <iostream>

int main() {
  int n;
  std::cin >> n;
  bool can = false;
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; ++j) {
      if (i * j == n) {
        can = true;
        break;
      }
    }
  }
  if (can) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
