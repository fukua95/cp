#include <iostream>
#include <string>
#include <map>

std::map<std::string, int> rem;

void solve() {
  int max_count = 0;
  for (const auto& a : rem) {
    if (a.second > max_count) {
      max_count = a.second;
    }
  }
  for (const auto& a : rem) {
    if (a.second == max_count) {
      std::cout << a.first << std::endl;
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  std::string s;
  for (int i = 0; i < n; ++i) {
    std::cin >> s;
    ++rem[s];
  }
  solve();
  return 0;
}
