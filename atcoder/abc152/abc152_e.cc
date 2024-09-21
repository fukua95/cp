#include <iostream>
#include <cmath>
#include <map>

const int P = (int)1e9 + 7;
const int MAXN = (int)1e4;

int a[MAXN];

void calc_factor(int x, std::map<int, int>* factor) {
  int sqrt = std::sqrt(x + 0.5);
  for (int i = 2; i <= sqrt; ++i) {
    if (x % i == 0) {
      while (x % i == 0) {
        (*factor)[i] += 1;
        x /= i;
      }
    }
  }
  if (x > 1) (*factor)[x] += 1;
}

int64_t power(int64_t x, int64_t y) {
  int64_t ans = 1;
  x %= P;
  while (y > 0) {
    if (y & 1) ans = ans * x % P;
    x = x * x % P;
    y >>= 1;
  }
  return ans;
}

int64_t inv(int64_t x) {
  return power(x, P - 2);
}

int64_t solve(int n) {
  std::map<int, int> lcm_factor;
  std::map<int, int> factor;
  for (int i = 0; i < n; ++i) {
    factor.clear();
    calc_factor(a[i], &factor);
    for (const auto& node : factor) {
      int prime = node.first;
      int num = node.second;
      // std::cout << prime << " " << num << std::endl;
      if (!lcm_factor.count(prime)) {
        lcm_factor[prime] = num;
      } else {
        if (lcm_factor[prime] < num) {
          lcm_factor[prime] = num;
        }
      }
    }
  }
  int64_t lcm = 1;
  for (const auto& node : lcm_factor) {
    int64_t cur = power(node.first, node.second);
    lcm = lcm * cur % P;
  }
  // std::cout << "lcm = " << lcm << std::endl;
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = (ans + lcm * inv(a[i]) % P) % P;
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::cout << solve(n) << std::endl;
  return 0;
}
