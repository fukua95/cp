#include <iostream>

const int MAXN = (int)2e5;

int a[MAXN];

int main() {
  int n;
  std::cin >> n;
  int xor_sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    xor_sum ^= a[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cout << (xor_sum ^ a[i]) << " ";
  }
  std::cout << std::endl;
  return 0;
}
