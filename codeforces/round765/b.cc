#include <iostream>
#include <unordered_map>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, a;
    std::cin >> n;
    std::unordered_map<int, int> pos;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
      std::cin >> a;
      if (pos.find(a) != pos.end()) {
        int pre = pos[a];
        int cur = pre + (n - i);
        if (cur > ans) {
          ans = cur;
        }
      }
      pos[a] = i;
    }
    std::cout << ans << std::endl;
  }
  return 0;
}