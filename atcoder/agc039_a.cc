#include <iostream>
#include <string>

using ll_t = long long;

ll_t solve(const std::string &s, int k) {
  ll_t res = 0;
  int len = s.length();
  int pos = 1;
  while (pos < len && s[pos] == s[0]) ++pos;
  if (pos == len) return static_cast<ll_t>(len) * k / 2;
  
  bool pre_has_changed = false;
  bool last_char_changed = false;
  for (int i = (pos + 1) % len; i % len != pos; i = (i + 1) % len) {
    if (s[i] == s[(i - 1 + len) % len] && !pre_has_changed) {
      ++res;
      pre_has_changed = true;
      if (i == len - 1) last_char_changed = true;
    } else {
      pre_has_changed = false;
    }
  }
  res *= k;
  if (s[0] == s[len - 1] && !last_char_changed && pos % 2 == 1) --res;
  return res;
}

int main() {
  int k;
  std::string s;
  std::cin >> s >> k;
  std::cout << solve(s, k) << std::endl;
  return 0;
}
