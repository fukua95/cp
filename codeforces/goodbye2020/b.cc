#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    int ma = a[n - 1] + 2;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] + 1 < ma) a[i] += 1;
      ma = a[i];
    }

    std::cout << std::unique(a.begin(), a.end()) - a.begin() << std::endl;
  }
  return 0;
}