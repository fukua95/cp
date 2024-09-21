#include <iostream>
#include <vector>
#include <set>

const int MAXN = (int)3e5 + 1;

std::set<int> bomb_pos[MAXN];

int main() {
  int h, w, m;
  std::cin >> h >> w >> m;
  std::vector<int> col_bomb_num(w + 1);
  for (int i = 0, r, c; i < m; ++i) {
    std::cin >> r >> c;
    bomb_pos[r].insert(c);
    ++col_bomb_num[c];
  }

  std::vector<int> max_col;
  int max = 0;
  for (int i = 1; i <= w; ++i) {
    int cur = col_bomb_num[i];
    if (cur == 0) continue;
    if (cur > max) {
      max_col.clear();
      max_col.emplace_back(i);
      max = cur;
    } else if (cur == max) {
      max_col.emplace_back(i);
    }
  }

  max = 0;
  for (int i = 1; i <= h; ++i) {
    int cur = bomb_pos[i].size() + col_bomb_num[max_col[0]];
    if (max_col.size() <= bomb_pos[i].size()) {
      bool flag = true;
      for (const auto& c : max_col) {
        if (bomb_pos[i].find(c) == bomb_pos[i].end()) {
          flag = false;
          break;
        }
      }
      if (flag) --cur;
    }
    if (cur > max) max = cur;
  }

  std::cout << max << std::endl;

  return 0;
}
