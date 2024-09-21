#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>

using ll_t = long long;
const int MAXN = 1e5;

struct Node {
  int value, pos;
  Node(int v = 0, int p = 0) : value(v), pos(p) {}
};
Node p[MAXN];
std::set<int> st;

ll_t solve(int n) {
  std::sort(p, p + n, [](const Node &a, const Node &b) {
    return a.value > b.value;
  });
  st.emplace(-1);
  st.emplace(n);
  ll_t res = 0;
  for (int i = 0; i < n; ++i) {
    int pos = p[i].pos;
    int l1 = -1, l2, r1, r2 = n;
    auto iter = st.lower_bound(pos);
    if (*iter == n) {
      r1 = n;
      --iter;
      l2 = *iter;
      if (iter != st.begin()) l1 = *(--iter);
    } else {
      auto iter2 = iter;
      r1 = *iter;
      ++iter;
      r2 = *iter;
      --iter2;
      l2 = *iter2;
      if (iter2 != st.begin()) l1 = *(--iter2);
    }
    // printf("pos = %d value = %d\n", pos, p[i].value);
    // printf("l1 = %d l2 = %d r1 = %d r2 = %d\n", l1, l2, r1, r2);
    ll_t num = (ll_t)(l2 - l1) * (r1 - pos) + (ll_t)(pos - l2) * (r2 - r1);
    res += num * p[i].value;
    st.emplace(pos);
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0, value; i < n; ++i) {
    scanf("%d", &value);
    p[i] = Node(value, i);
  }
  printf("%lld\n", solve(n));
  return 0;
}

