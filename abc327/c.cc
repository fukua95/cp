#include <bits/stdc++.h>

int main() {
  std::vector<std::vector<int>> a(9, std::vector<int>(9));

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      std::cin >> a[i][j];
    }
  }

  auto check = [](const std::vector<int> &a) -> bool {
    int count = 0;
    for (auto x : a) {
      count |= (1 << x);
    }
    return count == 1022;  // 1024 - 1 - 2^0 = 1022
  };

  bool ans = true;
  for (int i = 0; i < 9; ++i) {
    ans = ans && check(a[i]);
  }
  for (int j = 0; j < 9; ++j) {
    std::vector<int> cur;
    for (int i = 0; i < 9; ++i) {
      cur.push_back(a[i][j]);
    }
    ans = ans && check(cur);
  }
  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      std::vector<int> cur;
      for (int x = i; x < i + 3; ++x) {
        for (int y = j; y < j + 3; ++y) {
          cur.push_back(a[x][y]);
        }
      }
      ans = ans && check(cur);
    }
  }
  if (ans)
    std::cout << "Yes\n";
  else
    std::cout << "No\n";
  return 0;
}