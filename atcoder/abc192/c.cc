#include <iostream>
#include <vector>

int calc(int a) {
  std::vector<int> dig(10, 0);
  while (a > 0) {
    dig[a % 10]++;
    a /= 10;
  }
  int x = 0, y = 0;
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j <= dig[i]; ++j) {
      x = x * 10 + i;
    }
  }
  for (int i = 9; i >= 0; --i) {
    for (int j = 1; j <= dig[i]; ++j) {
      y = y * 10 + i;
    } 
  }
  return y - x;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  int cur = n;
  for (int i = 1; i <= k; ++i) {
    cur = calc(cur);
    // printf("i = %d, cur = %d\n", i, cur);
  }
  std::cout << cur << std::endl;
  return 0;
}
