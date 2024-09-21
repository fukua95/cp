#include <bits/stdc++.h>

auto LessOrEqual(const std::vector<int> &pos, int v) -> int {
  if (pos[0] > v) {
    return -1;
  }
  int l = 0;
  int r = pos.size();
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (pos[mid] <= v) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> pos(n);
  std::vector<int64_t> size(n);
  for (int i = 0; i < n; i++) {
    std::cin >> pos[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> size[i];
  }
  for (int i = 1; i < n; i++) {
    size[i] += size[i - 1];
  }

  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    int x = LessOrEqual(pos, l);
    int y = LessOrEqual(pos, r);
    if (pos[x] == l) {
      x--;
    }

    int64_t ans;
    if (y < 0) {
      ans = 0;
    } else {
      ans = size[y] - (x < 0 ? 0 : size[x]);
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
