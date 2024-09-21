#include <iostream>
#include <map>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::map<int, int> has;
  for (int i = 0, v; i < m; ++i) {
    std::cin >> v;
    has[v] = 1;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur = a[i] % 1000;
    if (has.find(cur) != has.end()) {
      ++ans;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}