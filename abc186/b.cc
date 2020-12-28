#include <iostream>
#include <vector>

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::vector<int>> a(h, std::vector<int>(w));
  int min = 101;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cin >> a[i][j];
      if (a[i][j] < min) min = a[i][j];
    }
  }

  int ans = 0;
  for (const auto& vec : a) {
    for (const auto& val : vec) {
      ans += val - min;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}