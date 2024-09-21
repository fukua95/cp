#include <iostream>
#include <string>

const int P = (int)1e9 + 7;
const int MAXN = (int)2e6 + 1;

int factorial[MAXN];

void init(int n) {
  factorial[0] = 1;
  for (int i = 1; i <= n; ++i) {
    factorial[i] = 1LL * factorial[i - 1] * i % P;
  }
}

int64_t pow(int64_t x, int y) {
  int64_t ans = 1;
  while (y > 0) {
    if (y & 1) ans = ans * x % P;
    x = x * x % P;
    y >>= 1;
  }
  return ans;
}

int64_t comb(int x, int y) {
  return factorial[x] * pow(factorial[y], P - 2) % P * 
         pow(factorial[x - y], P - 2) % P;
}

int solve(int op_num, int s_len) {
  init(op_num + s_len);
  int64_t ans = 0;
  for (int i = 0; i <= op_num; ++i) {
    ans += pow(25, i) * comb(i + s_len - 1, i) % P * pow(26, op_num - i) % P;
    if (ans >= P) ans -= P;
  }
  return ans;
}

int main() {
  int op_num;
  std::string s;
  std::cin >> op_num >> s;
  std::cout << solve(op_num, s.length()) << std::endl;
  return 0;
}
