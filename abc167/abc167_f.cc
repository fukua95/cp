#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

pair<int, int> get_bracket(const std::string& s) {
  int r_bracket = 0, l_bracket = 0;
  for (const auto& c : s) {
    if (c == '(') {
      ++l_bracket;
    } else {
      if (l_bracket > 0) --l_bracket;
      else ++r_bracket;
    }
  }
  return std::make_pair(l_bracket, r_bracket);
}

bool solve(vector<pair<int, int>>& ge_0, vector<pair<int, int>>& l_0) {
  std::sort(ge_0.begin(), ge_0.end(), [](const auto& x, const auto& y) {
    return x.second < y.second; 
  });
  std::sort(l_0.begin(), l_0.end(), [](const auto& x, const auto& y) {
    return x.first > y.first;
  });
  int pre_sum = 0;
  for (const auto& [l, r] : ge_0) {
    pre_sum -= r;
    if (pre_sum < 0) return false;
    pre_sum += l;
  }
  for (const auto& [l, r] : l_0) {
    pre_sum -= r;
    if (pre_sum < 0) return false;
    pre_sum += l;
  }
  return pre_sum == 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<pair<int, int>> ge_0, l_0;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    auto p = get_bracket(s);
    if (p.first >= p.second) ge_0.emplace_back(p);
    else l_0.emplace_back(p);
  }
  if (solve(ge_0, l_0)) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
