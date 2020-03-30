#include <cstdio>
#include <utility>
#include <algorithm>
#include <map>

const int MAXN = (int)2e5 + 1;

int p[MAXN];
bool is_min[MAXN];  // is_min[i]:p[i]是不是[i,i+k-1]的min?
bool is_max[MAXN];  // is_max[i]:p[i]是不是[i-k+1,i]的max?

// Segment tree
struct Node {
  int min, max;
};
Node node[MAXN << 2];

void build(int rt, int l, int r) {
  if (l == r) {
    node[rt].min = node[rt].max = p[l];
    return;
  }
  int mid = (l + r) / 2;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  node[rt].min = std::min(node[rt << 1].min, node[rt << 1 | 1].min);
  node[rt].max = std::max(node[rt << 1].max, node[rt << 1 | 1].max);
}

Node query(int ql, int qr, int rt, int l, int r) {
  if (ql <= l && qr >= r) return node[rt];
  int mid = l + r >> 1;
  if (ql > mid) return query(ql, qr, rt << 1 | 1, mid + 1, r);
  else if (qr <= mid) return query(ql, qr, rt << 1, l, mid);
  Node left = query(ql, mid, rt << 1, l, mid);
  Node right = query(mid + 1, qr, rt << 1 | 1, mid + 1, r);
  Node res;
  res.min = std::min(left.min, right.min);
  res.max = std::max(left.max, right.max);
  return res;
}

int solve(int n, int k) {
  for (int i = 1; i <= n; ++i) is_min[i] = is_max[i] = false;

  build(1, 1, n);
  for (int l = 1; l + k - 1 <= n; ++l) {
    int r = l + k - 1;
    Node res = query(l, r, 1, 1, n);
    if (p[l] == res.min) is_min[l] = true;
    if (p[r] == res.max) is_max[r] = true;
  }

  int res = n - k + 1;
  for (int l = 2; l + k - 1 <= n; ++l) {
    if (is_min[l - 1] && is_max[l + k - 1]) --res;
  }
  // printf("%d\n", res);
  std::map<int, int> m;
  int len = 1;
  for (int i = 2; i <= n; ++i) {
    if (p[i] < p[i - 1]) {
      ++m[len];
      len = 1;
    } else {
      ++len;
    }
  }
  ++m[len];
  bool first = true;
  for (const auto &cur : m) {
    int len = cur.first, num = cur.second;
    // printf("len = %d num = %d\n", len, num);
    if (len < k) continue;
    if (first) {
      res -= num - 1;
      first = false;
    } else {
      res -= num;
    }
  }
  return res;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", p + i);
  printf("%d\n", solve(n, k));
  return 0;
}

