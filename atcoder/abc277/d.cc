#include <iostream>
#include <map>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::map<int, int> count;
  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    sum += a;
    count[a] += 1;
  }
  
  int pre = 0;
  int64_t pre_sum = 0;
  for (auto [k, v]: count) {
    if (k > pre) {
      break;
    } else {
      pre_sum += (int64_t)k * v;
      ++pre;
    }
  }
  std::vector<int> k_val;
  for (auto [k, v]: count) {
    if (k <= pre) continue;
    k_val.emplace_back(k);
  }
  int sz = k_val.size();
  if (sz > 0) {
    std::vector<int64_t> f(sz, 0);
    f[sz - 1] = (int64_t)k_val[sz - 1] * count[k_val[sz - 1]];
    if (k_val[sz - 1] == m - 1) {
      f[sz - 1] += pre_sum;
    }
    if (f[sz - 1] > pre_sum) pre_sum = f[sz - 1];
    for (int i = sz - 2; i >= 0; --i) {
      int cur = k_val[i];
      int nxt = k_val[i + 1];
      f[i] = (int64_t)cur * count[cur];
      if (cur == nxt - 1) {
        f[i] += f[i + 1]; 
      }
      if (f[i] > pre_sum) pre_sum = f[i];
    }
  }

  std::cout << sum - pre_sum << std::endl;
  return 0;
}