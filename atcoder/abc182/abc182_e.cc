#include <iostream>
#include <vector>

const int MAXN = 1502;

// 0: empty
// 1: block
// 2: blub
int maze[MAXN][MAXN];
int row_map[MAXN][MAXN];
int col_map[MAXN][MAXN];

int solve(int h, int w) {
  int cur = 1;
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      if (maze[i][j] == 1) ++cur;
      else row_map[i][j] = cur;
    }
    ++cur;
  }
  for (int j = 1; j <= w; ++j) {
    for (int i = 1; i <= h; ++i) {
      if (maze[i][j] == 1) ++cur;
      else col_map[i][j] = cur;
    }
    ++cur;
  }
  
  std::vector<bool> is_ill(cur, false);

  for (int i = 1; i <= h; ++i) {
    for (int j = 1 ;j <= w; ++j) {
      if (maze[i][j] == 2) {
        is_ill[row_map[i][j]] = true;
        is_ill[col_map[i][j]] = true;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      int r_m = row_map[i][j];
      int c_m = col_map[i][j];
      if (is_ill[r_m] || is_ill[c_m]) ++ans;
    }
  }
  return ans;
}

int main() {
  int h, w, n, m;
  std::cin >> h >> w >> n >> m;
  for (int i = 1, x, y; i <= n; ++i) {
    std::cin >> x >> y;
    maze[x][y] = 2;
  }
  for (int i = 1, x, y; i <= m; ++i) {
    std::cin >> x >> y;
    maze[x][y] = 1;
  }

  std::cout << solve(h, w) << std::endl;
  return 0;
}