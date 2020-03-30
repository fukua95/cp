#include <iostream>
#include <unordered_map>

int main() {
  std::unordered_map<int, int> rem;
  int n;
  std::cin >> n;
  for (int i= 0, a; i < n; ++i) {
    std::cin >> a;
    ++rem[a];
  }
  bool ans = true;
  for (const auto& v: rem) {
    if (v.second > 1) {
      ans = false;
      break;
    }
  }
  if (ans) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;
  return 0;
}
