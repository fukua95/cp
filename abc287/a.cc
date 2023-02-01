#include <iostream>
#include <string>

int main() {
  int n;
  std::cin >> n;
  int yes = 0, no = 0;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    if (s[0] == 'F')
      ++yes;
    else
      ++no;
  }
  if (yes > no)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;
  return 0;
}