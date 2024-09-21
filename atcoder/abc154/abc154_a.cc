#include <iostream>
#include <string>

int main() {
  std::string s, t, u;
  int a, b;
  std::cin >> s >> t >> a >> b >> u;
  if (u == s) --a;
  else --b;
  std::cout << a << " " << b << std::endl;
  return 0;
}
