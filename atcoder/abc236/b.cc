#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> count(n + 1);
  for (int i = 1, a; i < 4 * n; ++i) {
    std::cin >> a;
    ++count[a];
  }
  for (int i = 1; i <= n; ++i) {
    if (count[i] != 4) {
      std::cout << i << std::endl;
    }
  }
  return 0;
}