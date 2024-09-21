#include <iostream>

const int MAXN = 50;

int a[MAXN];

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ans += a[i] * a[j];
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
