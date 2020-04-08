#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> a;

bool solve(int n, int m) {
  std::sort(a.begin(), a.end());
  int sum = 0;
  for (int i = 0; i < n; ++i) sum += a[i];
  return a[n - m] * 4 * m >= sum;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    a.emplace_back(x);
  }
  if (solve(n, m)) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
