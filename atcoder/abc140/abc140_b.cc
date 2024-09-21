#include <iostream>

const int MAXN = 20 + 1;

int a[MAXN], b[MAXN], c[MAXN];

int solve(int n) {
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    res += b[a[i]];
    if (i < n && a[i] + 1 == a[i + 1]) res += c[a[i]];
  }
  return res;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  for (int i = 1; i <= n; ++i) std::cin >> b[i];
  for (int i = 1; i < n; ++i) std::cin >> c[i];
  std::cout << solve(n) << std::endl;
  return 0;
}
