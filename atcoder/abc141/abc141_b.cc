#include <iostream>
#include <string>

int main() {
  std::string str;
  std::cin >> str;

  bool ans = true;
  for (int i = 0, len = str.length(); i < len && ans; ++i) {
    if (i % 2 == 0 && str[i] == 'L') ans = false;
    else if (i % 2 == 1 && str[i] == 'R') ans = false;
  }
  
  if (ans) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
