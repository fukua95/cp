#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> pos[10];

bool find(int a, int b, int c, int n) {
  auto lower_bound = [&](int x, int min) -> int {
    auto iter = std::lower_bound(pos[x].begin(), pos[x].end(), min);
    if (iter == pos[x].end()) return n;
    return *iter;
  };
  
  int cur = lower_bound(a, 0);
  cur = lower_bound(b, cur + 1);
  cur = lower_bound(c, cur + 1);
  return cur < n;
}

int solve(const std::string &str, int n) {
  for (int i = 0; i < n; ++i) {
    pos[str[i] - '0'].emplace_back(i);
  }
  int res = 0;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j <10; ++j) {
      for (int k = 0; k < 10; ++k) {
        if (find(i, j, k, n)) ++res;
      }
    }
  }
  return res;
}

int main() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  std::cout << solve(str, n) << std::endl;
  return 0;
}
