#include <bits/stdc++.h>

int n, k, res;
std::vector<int> a;
std::vector<int> cur;

void DFS(int p, int sum) {
  if (p == n) {
    if (sum % k == 0) {
      for (auto v : cur) {
        std::cout << v << " ";
      }
      std::cout << std::endl;
    }
    return;
  }
  for (int i = 1; i <= a[p]; i++) {
    cur[p] = i;
    DFS(p + 1, sum + i);
  }
}

int main() {
  std::cin >> n >> k;
  a = std::vector<int>(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  res = 0;
  cur = std::vector<int>(n);
  DFS(0, 0);
  return 0;
}