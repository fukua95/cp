#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int count = 0;
  for (int i = 1; i <= n; ++i) {
    bool has_7 = false;
    for (int j = i; j > 0; j /= 10) {
      if (j % 10 == 7) {
        has_7 = true;
        break;
      }
    }
    for (int j = i; j > 0; j /= 8) {
      if (j % 8 == 7) {
        has_7 = true;
        break;
      }
    }
    if (!has_7) ++count;
  }
  std::cout << count << std::endl;
  return 0;
}