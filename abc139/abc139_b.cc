#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  int ans;
  for (int i = 0; ; ++i) {
    if (i * a - i + 1 >= b) {
      ans = i;
      break;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
