#include <iostream>
#include <vector>

int solve(int n, int64_t k, const std::vector<int>& to) {
  std::vector<int> dis(n + 1, -1);
  int step = 0, pos = 1;
  dis[pos] = 0;
  int loop_start, loop_len;
  while (true) {
    if (step == k) return pos;
    int next = to[pos];
    if (dis[next] != -1) {
      loop_start = next;
      loop_len = dis[pos] - dis[next] + 1;
      break;
    }
    ++step;
    dis[next] = dis[pos] + 1;
    pos = next;
  }
  k = (k - dis[loop_start]) % loop_len;
  int ans = loop_start;
  while (k--) ans = to[ans];
  return ans;
}

int main() {
  int n;
  int64_t k;
  std::cin >> n >> k;
  std::vector<int> to(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> to[i];
  }
  std::cout << solve(n, k, to) << std::endl;
  return 0;
}
