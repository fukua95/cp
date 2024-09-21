#include <iostream>

const int MAXN = (int)1e5 + 1;

int count[MAXN];  // count[i] = the number of 'i' in the array.

int main() {
  int n;
  std::cin >> n;
  int64_t sum = 0;
  for (int i = 0, in; i < n; ++i) {
    std::cin >> in;
    sum += in;
    ++count[in];
  }
  int q;
  std::cin >> q;
  for (int i = 0, cur, nxt; i < q; ++i) {
    std::cin >> cur >> nxt;
    sum += 1LL * count[cur] * (nxt - cur);
    std::cout << sum << std::endl;
    count[nxt] += count[cur];
    count[cur] = 0;
  }
  return 0;
}
