#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll_t = long long;

std::vector<int> pos[26];

ll_t solve(const std::string &s, const std::string &t) {
  int s_len = s.length();
  for (int i = 0; i < s_len; ++i) {
    pos[s[i] - 'a'].emplace_back(i);
  }
  int num = 1, index = -1;
  int t_len = t.length();
  for (int i = 0; i< t_len; ++i) {
    int ch = t[i] - 'a';
    if (pos[ch].empty()) return -1;
    auto iter = std::upper_bound(pos[ch].begin(), pos[ch].end(), index);
    if (iter == pos[ch].end()) {
      ++num;
      index = -1;
      iter = std::upper_bound(pos[ch].begin(), pos[ch].end(), index);
    }
    index = *iter;
  }
  return (ll_t)s_len * (num - 1) + index + 1;
}

int main() {
  std::string s, t;
  std::cin >> s >> t;
  std::cout << solve(s, t) << std::endl;
  return 0;
}
