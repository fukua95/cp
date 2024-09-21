#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int n = s.length();
  bool flag = true;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0 && !(s[i] - 'a' >= 0 && s[i] - 'a' <= 25)) 
      flag = false;
    if (i % 2 == 1 && !(s[i] - 'A' >= 0 && s[i] - 'A' <= 25))
      flag = false;
  }
  if (flag) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
