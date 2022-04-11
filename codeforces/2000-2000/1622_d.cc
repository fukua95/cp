#include <cassert>
#include <iostream>
#include <string>
#include <vector>

const int P = 998244353;

void init(std::vector<std::vector<int>>& comb, int n) {
  for (int i = 0; i <= n; ++i) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      comb[i][j] = (((int64_t)comb[i - 1][j] + comb[i - 1][j - 1]) % P);
    }
  }
}

int64_t solve(const std::vector<int>& a, int n, int limit) {
  // 特殊处理limit = 0 的情况.
  if (limit == 0) return 1;

  // 特殊处理无法操作的情况.
  int one_count = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) ++one_count;
  }
  if (one_count < limit) return 1;

  std::vector<std::vector<int>> comb(n + 1, std::vector<int>(n + 1, 0));
  init(comb, n);

  // 对于a[i]=1,维护一个区间[to_l[i], to_r[i]].
  // 区间具有性质:
  // 1. a[i]是区间的第一个1.
  // 2. 恰好有limit个1.
  // 3. 区间尽量大.
  std::vector<int> to_l(n, 0);
  std::vector<int> to_r(n, 0);

  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      int cur = i;
      while ((cur - 1) >= 0 && a[cur - 1] == 0) --cur;
      to_l[i] = cur;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      int one_count = 1;
      int cur = i + 1;
      for (; cur < n; ++cur) {
        one_count += (a[cur] == 1);
        if (one_count > limit) break;
      }
      if (one_count >= limit) to_r[i] = cur - 1;
    }
  }

  /*
    for (int i = 0; i < n; ++i) {
      if (a[i] == 1) {
        std::cout << "i = " << i << " l = " << to_l[i] << " r = " << to_r[i]
                  << std::endl;
      }
    }
    */

  int64_t ans = 0;
  // 对于每一个a[i]=1的区间[to_l[i], to_r[i]]，计算区间对ans的贡献.
  int pre_one_pos = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] != 1 || to_r[i] == 0) continue;
    ans += comb[to_r[i] - to_l[i] + 1][limit];
    if (pre_one_pos != -1) {
      int pre_r = to_r[pre_one_pos];
      int64_t dup = comb[to_r[pre_one_pos] - to_l[i] + 1][limit - 1];
      ans = (ans - dup + P) % P;
    }
    pre_one_pos = i;
  }

  return ans;
}

int main() {
  int n, limit;
  std::string s;
  std::cin >> n >> limit >> s;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
  }

  std::cout << solve(a, n, limit) << std::endl;
  return 0;
}