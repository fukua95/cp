#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> last_occurred(n + 1, -1);  // a[i] <= n, 用 vector 代替 map.
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    int v = a[i];
    int start = last_occurred[v] + 1;
    ans += static_cast<int64_t>(i - start + 1) * (n - i);
    last_occurred[v] = i;
  }
  std::cout << ans << std::endl;
  return 0;
}