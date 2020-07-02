#include <iostream>
#include <vector>

int main() {
  int64_t n;
  std::cin >> n;
  std::vector<char> ans;
  while (true) {
    --n;
    ans.emplace_back(n % 26 + 'a');
    n /= 26;
    if (n == 0) break;
  }
  for (auto iter = ans.rbegin(); iter != ans.rend(); ++iter) {
    std::cout << *iter;
  }
  std::cout << std::endl;
  return 0;
}
