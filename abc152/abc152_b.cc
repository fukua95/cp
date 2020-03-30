#include <iostream>
#include <algorithm>

int main() {
  int a, b;
  std::cin >> a >> b;
  if (a > b) std::swap(a, b);
  for (int i = 0; i < b; ++i) std::cout << a;
  std::cout << std::endl;
  return 0;
}
