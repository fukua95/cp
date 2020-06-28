#include <iostream>

const int MAXN = (int)2e5;

int64_t a[MAXN], b[MAXN];

int solve(int a_len, int b_len, int total_time) {
  for (int i = 1; i < a_len; ++i) {
    a[i] += a[i - 1];
  }
  for (int i = 1; i < b_len; ++i) {
    b[i] += b[i - 1];
  }
  
  int p_a = 0, p_b = b_len - 1;
  while (p_b >= 0 && b[p_b] > total_time) {
    --p_b;
  }
  int ans = p_b + 1;
  while (p_a < a_len) {
    while (p_b >= 0 && a[p_a] + b[p_b] > total_time) {
      --p_b;
    }
    if (p_b < 0 && a[p_a] > total_time) {
      break;
    }
    int cur = p_a + p_b + 2;
    if (cur > ans) ans = cur;
    ++p_a;
  }
  return ans;
}

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < m; ++i) std::cin >> b[i];
  
  std::cout << solve(n, m, k) << std::endl;
  return 0;
}
