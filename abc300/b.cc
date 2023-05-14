#include <iostream>
#include <string>
#include <vector>

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> a(h), b(h);
  for (int i = 0; i < h; ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i < h; ++i) {
    std::cin >> b[i];
  }
  bool can = true;
  for (int s = 0; s < h; ++s) {
    for (int t = 0; t < w; ++t) {
      can = true;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (a[(i + s) % h][(j + t) % w] != b[i][j]) {
            can = false;
          }
        }
      }
      if (can) break;
    }
    if (can) break;
  }
  if (can)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}