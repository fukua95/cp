#include <iostream>
#include <vector>
#include <set>

int main() {
  int n;
  std::cin >> n;
  int len = 1 << n;
  std::multiset<int> st;
  for (int i = 0, in; i < len; ++i) {
    std::cin >> in;
    st.emplace(-in);
  }
  std::vector<int> obtained_data;
  obtained_data.emplace_back(*st.begin());
  st.erase(st.begin());
  bool ans = true;
  for (int i = 1; i <= n; ++i) {
    std::vector<int> new_data;
    for (const auto &cur : obtained_data) {
      auto iter = st.upper_bound(cur);
      if (iter == st.end()) {
        ans = false;
        break;
      }
      new_data.emplace_back(*iter);
      st.erase(iter);
    }
    if (!ans) break;
    for (const auto &cur : new_data) {
      obtained_data.emplace_back(cur);
    }
    // std::sort(obtained_data.begin(), obtained_data.end());
  }
  if (ans) puts("Yes");
  else puts("No");
  return 0;
}

