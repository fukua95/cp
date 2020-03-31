#include <iostream>
#include <utility>
#include <cstdlib>

const int MAXN = (int)1e5 + 3;
const int64_t INF = (int64_t)1e15;
int64_t s[MAXN];
int64_t t[MAXN];

int binary_search(int64_t a[], int n, int64_t x) {
  int l = 1, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (a[mid] <= x)
      l = mid;
    else
      r = mid;
  }
  return l;
}

std::pair<int64_t, int64_t> get(int64_t a[], int n, int64_t x) {
  std::pair<int64_t, int64_t> res(-INF, INF);
  if (x <= a[1]) 
    res = std::make_pair(-INF, a[1]);
  else if (x >= a[n])
    res = std::make_pair(a[n], INF);
  else {
    int index = binary_search(a, n, x);
    res = std::make_pair(a[index], a[index + 1]);
  }
  return res;
}

int64_t calc(int64_t x, std::pair<int64_t, int64_t> u, std::pair<int64_t, int64_t> v) {
  int64_t uf = u.first, us = u.second;
  int64_t vf = v.first, vs = v.second;
  int64_t res = abs(x - uf) + abs(uf - vf);
  res = std::min<int64_t>(res, abs(x - uf) + abs(uf - vs));
  res = std::min<int64_t>(res, abs(x - us) + abs(us - vf));
  res = std::min<int64_t>(res, abs(x - us) + abs(us - vs));
  return res;
}

int64_t solve(int n, int m, int64_t x) {
  std::pair<int64_t, int64_t> u = get(s, n, x);
  std::pair<int64_t, int64_t> v = get(t, m, x);
  return std::min(calc(x, u, v), calc(x, v, u));
}

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) 
    std::cin >> s[i];
  for (int i = 1; i <= m; ++i)
    std::cin >> t[i];
  for (int i = 1; i <= q; ++i) {
    int64_t x;
    std::cin >> x;
    std::cout << solve(n, m, x) << std::endl;
  }
  return 0;
}
