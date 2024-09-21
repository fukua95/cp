#include <iostream>
#include <vector>
#include <set>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::set<int> st;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        st.insert(a[i] - a[j]);
      }
    }
    std::cout << st.size() << std::endl;
  }
  return 0;
}