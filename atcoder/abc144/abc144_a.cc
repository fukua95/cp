#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  int ans = -1;
  if (1 <= a && a <= 9 && 1 <= b && b <= 9) {
    ans = a * b; 
  }
  std::cout << ans << std::endl;
  return 0;
}
