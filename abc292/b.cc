#include <iostream>
#include <vector>

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> score(n + 1, 0);
  for (int i = 0; i < q; ++i) {
    int t, id;
    std::cin >> t >> id;
    if (t == 1) {
      score[id] += 1;
    } else if (t == 2) {
      score[id] += 2;
    } else {
      if (score[id] >= 2) {
        std::cout << "Yes" << std::endl;
      } else {
        std::cout << "No" << std::endl;
      }
    }
  }
  return 0;
}