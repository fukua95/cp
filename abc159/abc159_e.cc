#include <iostream>
#include <cstring>
#include <string>

const int MAXH = 10;
const int MAXW = 1000;
const int INF = MAXW * MAXW;

int a[MAXH][MAXW];
int f[MAXH][MAXW];

int calc(int n, int w, int sum) {
  int ans = 0;
  for (int j = 0; j < w; ++j) {
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (f[i][j] > sum) return INF;
      if (j < w - 1 && f[i][j] + f[i][j + 1] > sum) ok = false; 
    }
    if (ok) {
      for (int i = 0; i < n; ++i) {
        if (j < w - 1) f[i][j + 1] += f[i][j];
      }
    } else {
      ++ans;
    }
  }
  return ans;
}

int solve(int h, int w, int sum) {
  int min_count = h * w;
  int enum_num = 1 << (h - 1);
  for (int k = 0; k < enum_num; ++k) {
    memset(f, 0, sizeof(f));
    int tot = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        f[tot][j] += a[i][j];
      }
      if (i == h - 1 || ((k >> i) & 1)) ++tot;
    }

    int cur_count = tot - 1 + calc(tot, w, sum);
    if (cur_count < min_count) min_count = cur_count;
  }
  return min_count;
}

int main() {
  int h, w, sum;
  std::cin >> h >> w >> sum;
  std::string s;
  for (int i = 0; i < h; ++i) {
    std::cin >> s;
    for (int j = 0; j < w; ++j) {
      a[i][j] = s[j] - '0';
    }
  }
  std::cout << solve(h, w, sum) << std::endl;
  return 0;
}
