#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  bool flag = false;
  if (a == b && a != c) flag = true;
  else if (a == c && a != b) flag = true;
  else if (b == c && b != a) flag = true;
  if (flag) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
