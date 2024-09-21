#include <iostream>
#include <string>

bool solve(const std::string& s) {
  // [l, r)
  auto is_pali = [&](int l, int r) -> bool {
    int mid = (r - l) / 2 + l;
    for (int i = l; i < mid; ++i) {
      if (s[i] != s[r - 1 - i]) return false;
    }
    return true;
  };
  
  int len = s.length();
  int mid = len / 2;
  if (is_pali(0, len) && is_pali(0, mid) && is_pali(mid + 1, len))
    return true;
  return false;
}

int main() {
  std::string s;
  std::cin >> s;
  if (solve(s)) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
