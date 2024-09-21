#include <iostream>
#include <string>

bool solve(int n, const std::string &str) {
  if (n % 2 == 1) return false;
  int dis = n / 2;
  for (int i = 0; i < dis; ++i) {
    if (str[i] != str[i + dis]) return false;
  }
  return true;
}

int main() {
  int n;
  std::string str;
  std::cin >> n >> str;
  if (solve(n, str)) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
