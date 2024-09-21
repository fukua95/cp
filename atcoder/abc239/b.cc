#include <iostream>

int main() {
  int64_t a;
  std::cin >> a;
  if (a < 0) {
    a -= 9;
  }
  std::cout << a / 10 << std::endl;
  return 0;
}