#include <iostream>

int main() {
  auto pow5 = [](int i) -> int64_t {
    return (int64_t)i * i * i * i * i;
  };

  int n;
  std::cin >> n;
  for (int i = 0; i < 120; ++i) {
    int64_t x = pow5(i);
    for (int j = -120; j < i; ++j) {
      int64_t y = pow5(j);
      if (x - y == n) {
        std::cout << i << " " << j << std::endl;
        // std::cout << x << " " << y << std::endl;
        return 0;
      }
    }
  }
}
