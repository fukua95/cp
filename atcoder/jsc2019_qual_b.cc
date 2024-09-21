#include <iostream>

using ll_t = long long;
const int MAXN = 2000;
const int P = (int)1e9 + 7;

int a[MAXN];

ll_t solve(int n, int k) {
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[i] > a[j]) ++x;
      else if (a[i] < a[j]) ++y;
    }
  }
  ll_t res = (ll_t)k * (k + 1) / 2 % P * x + 
             (ll_t)k * (k - 1) / 2 % P * y;
  return res % P;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  std::cout << solve(n, k) << std::endl;
}
