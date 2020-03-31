#include <math.h>
#include <iostream>
#include <map>

using namespace std;
using LL = long long;
const int P = (int)1e9 + 7;
const int MAXN = (int)1e5 + 35;
map<int,int> factor;
int jie[MAXN];

void Init(int n) {
  jie[1] = 1;
  for (int i = 2;i <= n; ++i) {
    jie[i] = (LL)jie[i - 1] * i % P;
  }
}

LL Pow(int x, int y) {
  LL res = 1;
  while(y > 0) {
    if (y & 1)
      res = res * x % P;
    x = (LL)x * x % P;
    y >>= 1;
  }
  return res;
}

void Factorization(int m) {
  factor.clear();
  int sq = sqrt(m + 0.5);
  for (int i = 2; i <= sq && i <= m; ++i) {
    while (m % i == 0) {
      factor[i] += 1;
      m /= i;
    }
  }
  if (m > 1)
    factor[m] = 1;
}

LL C(int x, int y) {
  if (x < y) return 0;
  if (y == 0 || y == x) return 1;
  return (LL)jie[x] * Pow(jie[y], P - 2) % P * Pow(jie[x - y], P - 2) % P;
}

LL Solve(int n, int m) {
  Init(n + 35);
  Factorization(m);
  LL res = 1;
  for (auto node : factor) {
    int cur = node.second;
    res = res * C(cur + n - 1, cur) % P;
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  cout << Solve(n, m) << endl;
  return 0;
}
