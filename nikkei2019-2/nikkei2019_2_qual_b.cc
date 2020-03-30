#include <iostream>

using ll_t = long long;
const int MAXN = (int)1e5;
const int P = 998244353;

int dis[MAXN];  // The dis between vertex 1 and vertex i is dis[i].
int num[MAXN];


// Calc x^y % P.
ll_t pow(ll_t x, int y) {
  ll_t res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % P;
    x = x * x % P;
    y >>= 1;
  }
  return res;
}

int solve(int n) {
  if (dis[0] != 0) return 0;
  
  int max_dis = 0;
  for (int i = 0; i < n; ++i) {
    ++num[dis[i]];
    if (dis[i] > max_dis) max_dis = dis[i];
  }

  if (num[0] != 1) return 0;

  ll_t tree_num = 1;
  for (int i = 1; i <= max_dis; ++i) {
    tree_num = tree_num * pow(num[i - 1], num[i]) % P;
  }

  return static_cast<int>(tree_num);
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> dis[i];
  }
  std::cout << solve(n) << std::endl;
  return 0;
}
