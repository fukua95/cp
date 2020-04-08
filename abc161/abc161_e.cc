#include <iostream>
#include <string>
#include <vector>

const int MAXN = (int)2e5;

bool used[MAXN][2];

void solve(int len, int k, int c, const std::string& s) {
  for (int i = 0; i < len; ++i) used[i][0] = used[i][1] = false;
  
  int select_num = 0;
  int pre_pos = -c - 1;
  for (int i = 0; i < len; ++i) {
    if (s[i] == 'x' || i - pre_pos <= c) continue;
    used[i][0] = true;
    ++select_num;
    pre_pos = i;
    if (select_num == k) break;
  }
  int right = pre_pos;
  
  select_num = 0;
  pre_pos = len + c;
  for (int i = len - 1; i >= 0; --i) {
    if (s[i] == 'x' || pre_pos - i <= c) continue;
    used[i][1] = true;
    ++select_num;
    pre_pos = i;
    if (select_num == k) break;
  }
  int left = pre_pos;

  std::vector<int> ans;
  int x = 0, y = 0;
  for (int i = left; i <= right; ++i) {
    if (used[i][0]) ++x;
    if (used[i][1]) ++y;
    if (used[i][0] && used[i][1]) ans.emplace_back(i);
  }
  if (x + y > k) {
    for (const auto& v : ans)
      std::cout << v  + 1 << std::endl;
  }
}

int main() {
  int n, k, c;
  std::string s;
  std::cin >> n >> k >> c >> s;;
  solve(n, k, c, s);
  return 0;
}


