#include <iostream>
#include <vector>
#include <string>

int64_t solve(const std::string& s) {
  int n = s.length();
  int pre_ch = 'A';
  int pre_pos = n;
  int64_t ans = 0;
  std::vector<int> count(26, 0);
  for (int i = n - 1; i >= 1; --i) {
    if (s[i] == s[i - 1]) {
      ans += (s[i] == pre_ch ? pre_pos : n) - i - 1 - count[s[i] - 'a'];
      while (i > 0 && s[i - 1] == s[i]) {
        --i;
      }
      pre_pos = i;
      pre_ch = s[i];
      for (int j = 0; j < 26; ++j) count[j] = 0;
    } else {
      count[s[i] - 'a'] += 1;
    }
  }
  return ans;
}

int main() {
  std::string s;
  std::cin >> s;
  std::cout << solve(s) << std::endl;
  return 0;
}