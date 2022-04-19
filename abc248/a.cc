#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  bool has[10];
  for (int i = 0; i < 10; ++i) has[i] = false;
  for (const auto& c : s) {
    has[c - '0'] = true;
  }
  for (int i = 0; i < 10; ++i) {
    if (!has[i]) {
      std::cout << i << std::endl;
      return 0;
    }
  }
}