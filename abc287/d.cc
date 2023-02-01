#include <iostream>
#include <string>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  int s_len = s.length();
  int t_len = t.length();

  int pre_max = -1;
  for (int i = 0; i < t_len; ++i) {
    if (s[i] == '?' || t[i] == '?' || s[i] == t[i])
      ++pre_max;
    else
      break;
  }

  int suf_min = s_len;
  for (int i = s_len - 1; i >= s_len - t_len; --i) {
    int t_p = t_len + i - s_len;
    if (s[i] == '?' || t[t_p] == '?' || s[i] == t[t_p])
      --suf_min;
    else
      break;
  }

  for (int i = 0; i <= t_len; ++i) {
    int suf = s_len + i - t_len;
    if (i - 1 <= pre_max && suf >= suf_min)
      std::cout << "Yes" << std::endl;
    else
      std::cout << "No" << std::endl;
  }
  return 0;
}