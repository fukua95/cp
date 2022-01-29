#include <iostream>
#include <string>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> names(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> names[i];
  }
  std::vector<bool> will_stop(n, false);
  int cur = 0;
  for (int i = 0; i < m; ++i) {
    std::string a;
    std::cin >> a;
    while (cur < n && names[cur] != a) {
      ++cur;
    }
    will_stop[cur] = true;
    ++cur;
  }
  for (int i = 0; i < n; ++i) {
    if (will_stop[i])
      std::cout << "Yes" << std::endl;
    else
      std::cout << "No" << std::endl;
  }
  return 0;
}