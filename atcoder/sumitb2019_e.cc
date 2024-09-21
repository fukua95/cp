#include <iostream>

const int MAXN = (int)1e5 + 1;
const int P = (int)1e9 + 7;

int a[MAXN];
int num[MAXN];

int64_t solve(int n) {
  int64_t res = 1;
  num[0] = 3; 
  for (int i = 0; i < n; ++i) {
    res = res * num[a[i] - 1] % P;
    --num[a[i] - 1];
    ++num[a[i]];
  }
  return res;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    ++a[i];
  }
  std::cout << solve(n) << std::endl;
  return 0;
}
