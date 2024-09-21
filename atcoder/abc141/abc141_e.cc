#include <iostream>
#include <string>
#include <map>

std::string str;

bool check(int x) {
  int len = str.length();
  std::map<std::string, int> m;
  for (int l = 0; l + x <= len; ++l) {
    auto sub_str = str.substr(l, x);
    if (m.find(sub_str) != m.end()) {
      if (m[sub_str] + x <= l) 
        return true;
    } else {
      m[sub_str] = l;
    }
  }
  return false;
}

int solve(int n) {
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    // std::cout << "check " << mid <<" "<< check(mid) << std::endl;
    if (check(mid)) l = mid;
    else r = mid;
  }
  return l;
}

int main() {
  int n;
  std::cin >> n >> str;
  std::cout << solve(n) << std::endl;
  return 0;
}
