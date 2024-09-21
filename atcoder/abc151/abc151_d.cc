#include <iostream>
#include <string>
#include <queue>
#include <utility>

const int MAXN = 20;
const int INF = 400;

bool maze[MAXN][MAXN];  // '1' = road, '0' = wall.
bool is_vis[MAXN][MAXN];
int min_move[MAXN * MAXN][MAXN * MAXN];  // src -> dest

void bfs(int x, int y, int r, int c) {
  if (maze[x][y] == false) return;
  
  auto hash = [&](int i, int j) -> int {
    return i * c + j;
  };

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      is_vis[i][j] = false;
    }
  }

  std::queue<std::pair<int, int>> que;
  int dx[4] = {-1, 0, 0, 1};
  int dy[4] = {0, -1, 1, 0};
  que.emplace(x, y);
  is_vis[x][y] = true;
  int src_hash = hash(x, y);
  min_move[src_hash][src_hash] = 0;
  while (!que.empty()) {
    auto cur = que.front();
    que.pop();
    for (int k = 0; k < 4; ++k) {
      int i = cur.first + dx[k];
      int j = cur.second + dy[k];
      int cur_hash = hash(cur.first, cur.second);
      if (i < 0 || i >= r || j < 0 || j >= c) continue;
      if (is_vis[i][j] || maze[i][j] == false) continue;
      min_move[src_hash][hash(i, j)] = min_move[src_hash][cur_hash] + 1;
      is_vis[i][j] = true;
      que.emplace(i, j);
    } 
  }
}

int solve(int r, int c) {
  int tot = r * c; 
  for (int i = 0; i < tot; ++i) {
    for (int j = 0; j < tot; ++j) {
      min_move[i][j] = INF;
    }
  }
  
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      bfs(i, j, r, c);
    }
  }

  int res = 0;
  for (int i = 0; i < tot; ++i) {
    for (int j = 0; j < tot; ++j) {
      if (min_move[i][j] != INF && min_move[i][j] > res)
        res = min_move[i][j];
    }
  }
  return res;
}

int main() {
  int r, c;
  std::cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < c; ++j) {
      if (s[j] == '.') maze[i][j] = true;
      else maze[i][j] = false;
    }
  }
  std::cout << solve(r, c) << std::endl;
  return 0;
}
