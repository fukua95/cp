#include <iostream>
#include <string>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      std::string u = a[i];
      std::string v = a[j];
      bool can = true;
      for (int k = 0; k < m; ++k) {
        if (u[k] == 'x' && v[k] == 'x') {
          can = false;
          break;
        }
      }
      if (can) ++ans;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}