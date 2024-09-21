#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int a = n / 100;
  int b = n / 10 % 10;
  int c = n % 10;
  if (a == 7 || b == 7 || c == 7) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
