#include <iostream>
#include <vector>

int calc(const std::vector<std::vector<int>> &a, int pre_ans, int n, int set) {
  if (set == 0) return pre_ans;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if ((set & (1 << i)) != 0) {
      for (int j = i + 1; j < n; ++j) {
        if ((set & (1 << j)) != 0) {
          int cur_set = set & (~(1 << i)) & (~(1 << j));
          int cur_ans = calc(a, pre_ans ^ a[i][j], n, cur_set);
          if (cur_ans > ans) {
            ans = cur_ans;
          }
        }
      }
      break;
    }
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  n *= 2;
  std::vector<std::vector<int>> a(n - 1, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      std::cin >> a[i][j];
    }
  }

  std::cout << calc(a, 0, n, (1 << n) - 1) << std::endl;
  return 0;
}