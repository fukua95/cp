#include <iostream>
#include <algorithm>

const int MAXN = (int)1e5;

int r[MAXN], g[MAXN], c[MAXN];

int64_t calc_sum(int l, int r, int *a) {
  int64_t sum = 0;
  for (int i = l; i < r; ++i) sum += a[i];
  return sum;
}

int64_t solve(int get_r, int get_g, int r_num, int g_num, int c_num) {
  std::sort(r, r + r_num);
  std::sort(g, g + g_num);
  std::sort(c, c + c_num);

  int r_p = r_num - get_r;
  int g_p = g_num - get_g;
  int c_p = c_num - 1;
  int64_t sum = calc_sum(r_p, r_num, r) + calc_sum(g_p, g_num, g);

  while (c_p >= 0 && (r_p < r_num || g_p < g_num)) {
    bool is_r = true;
    int cur = r[r_p];
    if (r_p == r_num || (g_p < g_num && r[r_p] > g[g_p])) {
      is_r = false;
      cur = g[g_p];
    }
    if (cur >= c[c_p]) break;
    sum += c[c_p--] - cur;
    if (is_r) ++r_p;
    else ++g_p;
  }
  return sum;
}

int main() {
  int get_r, get_g, r_num, g_num, c_num;
  std::cin >> get_r >> get_g >> r_num >> g_num >> c_num;
  for (int i = 0; i < r_num; ++i) std::cin >> r[i];
  for (int i = 0; i < g_num; ++i) std::cin >> g[i];
  for (int i = 0; i < c_num; ++i) std::cin >> c[i];
  
  std::cout << solve(get_r, get_g, r_num, g_num, c_num) << std::endl;
  return 0;
}
