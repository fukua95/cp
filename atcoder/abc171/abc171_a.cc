#include <iostream>

int main() {
  char ch;
  std::cin >> ch;
  if (ch >= 'A' && ch <= 'Z') ch = 'A';
  else ch = 'a';
  std::cout << ch << std::endl;
  return 0;
}
