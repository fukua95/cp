#include <iostream>
#include <map>

const int MAXN = (int)2e5;

int a[MAXN];

int64_t solve(int n) {
  std::map<int, int> count;
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    if (count.count(i - a[i])) {
      ans += count[i - a[i]];
    }
    ++count[i + a[i]];
  }
  return ans;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::cout << solve(n) << std::endl;
  return 0;
}
