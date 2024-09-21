#include <iostream>
#include <string>
#include <vector>

const int64_t INF = (int64_t)1e15;

// 在 sum[l...r) 中二分查找最大的位置x，使得 sum[x] == val.
// 返回 [l,x] 的长度.
int calc(const std::vector<int> &sum, int ori_l, int ori_r, int val) {
  int l = ori_l, r = ori_r;
  if (sum[l] > val) return 0;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (sum[mid] > val)
      r = mid;
    else
      l = mid;
  }
  return l - ori_l + 1;
}

int64_t solve(int n, int m, int64_t rep, const std::string &s) {
  // sum[i] 表示 s[0...i] 的前缀和, 'x' = 1, 'o' = 0.
  std::vector<int> sum(n, 0);
  if (s[0] == 'x') sum[0] = 1;
  for (int i = 1; i < n; ++i) {
    sum[i] = sum[i - 1] + (s[i] == 'x');
  }

  int64_t ans = 0;
  // 枚举子串的起点: 0 -> n - 1
  for (int i = 0; i < n; ++i) {
    int pre = 0;
    int64_t cur = 0;
    if (i > 0) pre = sum[i - 1];
    if (sum[n - 1] - pre > rep) {
      cur = calc(sum, i, n, rep + pre);
    } else {
      int64_t cur_rep = rep - (sum[n - 1] - pre);
      int64_t full = cur_rep / sum[n - 1];
      cur_rep -= full * sum[n - 1];
      cur = (n - i) + full * n;
      if (full < m - 1) {
        cur = (n - i) + full * n + calc(sum, 0, n, cur_rep);
      } else {
        cur = (n - i) + (int64_t)(m - 1) * n;
      }
    }
    if (cur > ans) ans = cur;
  }
  return ans;
}

int main() {
  int n, m;
  int64_t rep;
  std::string s;
  std::cin >> n >> m >> rep;
  std::cin >> s;

  std::cout << solve(n, m, rep, s) << std::endl;

  return 0;
}