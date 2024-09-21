#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using ll_t = long long;
using pii = std::pair<int, int>;
const int MAXN = (int)1e5 + 1;
const ll_t INF = (ll_t)1e15;

struct SegmentTree {
  struct Node {
    int l, r;
    ll_t tag;  // 这个区间内，<=tag的值不变，>tag的值改为tag.
  };
  Node node[MAXN * 4];

  inline int ls(int p) { return p << 1; }
  inline int rs(int p) { return p << 1 | 1; }
  
  void PushUp(int rt) {
    node[rt].tag = std::max(node[ls(rt)].tag, node[rs(rt)].tag);  
  }

  void PushDown(int rt) {
    if (node[ls(rt)].tag > node[rt].tag) 
      node[ls(rt)].tag = node[rt].tag;
    if (node[rs(rt)].tag > node[rt].tag)
      node[rs(rt)].tag = node[rt].tag;
  }

  void Build(int rt, int l, int r) {
    node[rt].l = l;
    node[rt].r = r;
    node[rt].tag = INF;
    if (l == r && l == 1) node[rt].tag = 0;
    if (l == r) return;

    int mid = l + r >> 1;
    Build(ls(rt), l, mid);
    Build(rs(rt), mid + 1, r);
  }

  void Modify(int l, int r, ll_t x, int rt) {
    if (l <= node[rt].l && node[rt].r <= r) {
      if (node[rt].tag > x) node[rt].tag = x;
      return;
    }
    PushDown(rt);
    int mid = node[rt].l + node[rt].r >> 1;
    if (l <= mid) Modify(l, r, x, ls(rt));
    if (r > mid) Modify(l, r, x, rs(rt));
    PushUp(rt);
  }

  ll_t Query(int pos, int rt) {
    if (node[rt].l == node[rt].r) return node[rt].tag;
    PushDown(rt);
    int mid = node[rt].l + node[rt].r >> 1;
    ll_t res;
    if (pos <= mid) res = Query(pos, ls(rt));
    else res = Query(pos, rs(rt));
    PushUp(rt);
    return res;
  }
};

std::vector<pii> edges[MAXN];
SegmentTree tree;

ll_t solve(int n) {
  tree.Build(1, 1, n);
  for (int i = 1; i < n; ++i) {
    ll_t dis = tree.Query(i, 1);
    // printf("pos = %d dis = %lld\n", i, dis);
    for (const auto &edge : edges[i]) {
      int r = edge.first, c = edge.second;
      tree.Modify(i + 1, r, dis + c, 1);
    }
  }
  ll_t res = tree.Query(n, 1);
  if (res >= INF) res = -1;
  return res;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int l, r, c;
    scanf("%d %d %d", &l, &r, &c);
    edges[l].emplace_back(r, c);
  }
  printf("%lld\n", solve(n));
  return 0;
}
