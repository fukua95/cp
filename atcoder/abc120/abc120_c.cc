#include <iostream>
#include <string>
#include <cmath>

int main() {
  std::string str;
  std::cin >> str;
  int zero_num = 0;
  for (auto& ch : str) {
    if (ch == '0')
      ++zero_num;
  }
  std::cout << std::min(zero_num, (int)str.size() - zero_num) * 2 << std::endl;
  return 0;
}
