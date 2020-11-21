#include <iostream>
#include <vector>

int solve(const std::vector<int>& a) {
  int n = a.size();
  std::vector<int> as_seqs;
  int pre = -1, num = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] > pre) {
      ++num;
    } else {
      as_seqs.emplace_back(num);
      num = 1;
    }
    pre = a[i];
  }
  if (num != 0) as_seqs.emplace_back(num);

  int height = 0, pa_num = 1, son_num = 0;
  for (const auto& cur : as_seqs) {
    // std::cout << cur << std::endl;
    son_num += cur;
    --pa_num;
    if (pa_num == 0) {
      pa_num = son_num;
      son_num = 0;
      ++height;
    }
  }
  if (son_num > 0) ++height;
  return height;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::cout << solve(a) << std::endl;
  }
  return 0;
}