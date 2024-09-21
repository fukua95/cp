#include <iostream>
#include <vector>
#include <string>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  char cond1[4] = {'H', 'D', 'C', 'S'};
  char cond2[13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    std::string cur;
    std::cin >> cur;
    bool cond_ok = false;
    for (int j = 0; j < 4; ++j) {
      if (cur[0] == cond1[j]) {
        cond_ok = true;;
        break;
      }
    }
    if (!cond_ok) ok = false;

    cond_ok = false;
    for (int j = 0; j < 13; ++j) {
      if (cur[1] == cond2[j]) {
        cond_ok = true;
        break;
      }
    }
    if (!cond_ok) ok = false;


    for (int j = 0; j < i; ++j) {
      if (cur == a[j]) {
        ok = false;
      }
    }
    a[i] = cur;
  }
  if (ok) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}