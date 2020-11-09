#include <iostream>

int a[100];

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  
  int ans = 1, max_num = 0;
  for (int i = 2; i <= 1000; ++i) {
    int div = 0;
    for (int j = 0; j < n; ++j) {
      if (a[j] % i == 0) {
        ++div;
      }
    }
    if (div > max_num) {
      max_num = div;
      ans = i;
    }
  }
  
  std::cout << ans << std::endl;

  return 0;
}