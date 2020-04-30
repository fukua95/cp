#include <string>
#include <iostream>
#include <set>

int main() {
  std::set<std::string> count;
  std::string s;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> s; 
    count.emplace(s);
  }
  std::cout << count.size() << std::endl;
  return 0;
}
