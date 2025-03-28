// 找规律

#include <bits/stdc++.h>

int main() {
  int t;
  std::cin >> t;
  while (t-- > 0) {
    int n;
    std::cin >> n;
    if (n % 2 == 0) {
      std::cout << "-1" << std::endl;
    } else {
      for (int i = n; i >= 1; i--) {
        std::cout << i << " ";
      }
      std::cout << std::endl;
    }
  }
  return 0;
}