#include <iostream>

const int MAXN = (int)2e5 + 1;

int count[MAXN];

int main() {
  int n;
  std::cin >> n;
  for (int i = 2, u; i <= n; ++i) {
    std::cin >> u;
    ++count[u];
  }
  for (int i = 1; i <= n; ++i) 
    std::cout << count[i] << std::endl;
  return 0;
}
