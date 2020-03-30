#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::map<std::string, int> m;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    ans += m[s];
    ++m[s];
  }
  std::cout << ans << std::endl;
  return 0;
}
