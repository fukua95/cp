#include <iostream>
#include <queue>

int64_t solve(int k) {
  std::queue<int64_t> q;
  for (int i = 1; i < 10; ++i) q.push(i);
  while (k) {
    int64_t v = q.front();
    if (k == 1) return v;
    q.pop();
    int d = v % 10;
    if (d != 0) q.push(10 * v + d - 1);    
    q.push(10 * v + d);
    if (d != 9) q.push(10 * v + d + 1);
    --k;
  }
}

int main() {
  int k;
  std::cin >> k;
  std::cout << solve(k) << std::endl;
  return 0;
}
