#include <iostream>
#include <map>
#include <string>

int main() {
  std::string s;
  std::map<char, int> count;
  std::cin >> s;
  for (auto ch : s) {
    ++count[ch];
  }
  std::string ans;
  int i = 0;
  for (auto [ch, num] : count) {
    for (int j = 0; j < num; ++j) {
      ans += ch;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}