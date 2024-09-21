#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> min(n), max(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> min[i] >> max[i];
  }
  std::sort(min.begin(), min.end());
  std::sort(max.begin(), max.end());
  int ans;
  if (n % 2 == 1) {
    ans = max[n / 2] - min[n / 2] + 1;
  } else {
    double m1 = (max[n / 2 - 1] + max[n / 2]) / 2.0;
    double m2 = (min[n / 2 - 1] + min[n / 2]) / 2.0;
    ans = (m1 - m2) * 2 + 1;
  }
  std::cout << ans << std::endl;
  return 0;
}
