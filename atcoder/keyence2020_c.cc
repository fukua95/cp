#include <iostream>

int main() {
  int n, k, s;
  std::cin >> n >> k >> s;
  int other = s + 1;
  if (s == (int)1e9) other = s - 1;
  for (int i = 0; i < n; ++i) {
    if (i < k) std::cout << s << " ";
    else std::cout << other << " ";
  }
  std::cout << std::endl;
  return 0;
}
