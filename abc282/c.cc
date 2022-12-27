#include <iostream>
#include <string>

int main() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  bool closed = true;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '"') {
      closed = !closed;
    }
    if (s[i] == ',') {
      if (closed) {
        s[i] = '.';
      }
    }
  }
  std::cout << s << std::endl;
  return 0;
}