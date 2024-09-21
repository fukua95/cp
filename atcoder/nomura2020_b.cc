#include <iostream>
#include <string>
#include <algorithm>

int count(const std::string& s, char ch) {
  int num = 0;
  int len = s.length();
  char cur, pre = 'a';
  for (int i = 0; i < len; ++i) {
    char cur = s[i] == '?' ? ch : s[i];
    if (cur == 'D') {
      ++num;
      if (pre == 'P') ++num;
    }
    pre = cur;
  }
  return num;
}

void solve(std::string* s) {
  int p_num = count(*s, 'P');
  int d_num = count(*s, 'D');
  char ch = p_num >= d_num ? 'P' : 'D';
  int len = s->length();
  for (int i= 0; i < len; ++i) {
    if (s->at(i) == '?') 
      s->at(i) = ch;
  }
}

int main() {
  std::string s;
  std::cin >> s;
  solve(&s);
  std::cout << s << std::endl;
  return 0;
}
