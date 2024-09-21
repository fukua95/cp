#include <iostream>

int main() {
  int h1, m1, h2, m2, k;
  std::cin >>h1 >> m1 >> h2 >> m2 >> k;
  if (m2 < m1) {
    m2 += 60;
    --h2;
  }
  int len = m2 - m1 + (h2 - h1) * 60 - k;
  if (len < 0) len = 0;
  std::cout << len << std::endl;
  return 0;
}
