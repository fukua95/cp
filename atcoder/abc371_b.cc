#include <bits/stdc++.h>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<bool> is(n, false);
  for (int i = 0; i < m; i++) {
    int x;
    char b;
    std::cin >> x >> b;
    if (b == 'M' && !is[x]) {
      std::cout << "Yes\n";
      is[x] = true;
    } else {
      std::cout << "No\n";
    }
  }
  return 0;
}