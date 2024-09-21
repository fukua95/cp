#include <iostream>
#include <string>

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;
  if (n < 3200) std::cout << "red" << std::endl;
  else std::cout << s << std::endl;
  return 0;
}
