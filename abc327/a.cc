#include <iostream>
#include <string>

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;

  auto check = [](char x, char y) -> bool {
    return ((x == 'a' && y == 'b') || (x == 'b' && y == 'a'));
  };

  bool ans = false;

  for (int i = 0; i + 1 < n; ++i) {
    if (check(s[i], s[i + 1])) {
      ans = true;
      break;
    }
  }
  if (ans)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}