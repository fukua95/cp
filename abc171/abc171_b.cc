#include <iostream>
#include <algorithm>

const int MAXN = 1000;

int a[MAXN];

int main() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a, a + n);
  int sum = 0;
  for (int i = 0; i < k; ++i) {
    sum += a[i];
  }
  std::cout << sum << std::endl;
  return 0;
}
