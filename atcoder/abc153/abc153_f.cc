#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define x first
#define h second

const int MAXN = (int)2e5;

std::pair<int, int> a[MAXN];

// 区间更新，单点查询.
struct SegmentTree {
  static const int NODENUM = MAXN * 8 + 1;
  int64_t lazy[NODENUM];

  SegmentTree() {
    for (int i = 1; i < NODENUM; ++i) {
      lazy[i]= 0;
    } 
  }

  void PushDown(int rt) {
    if (lazy[rt] == 0) return;
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
  }

  void Update(int ul, int ur, int add_val, int l, int r, int rt) {
    if (ul <= l && ur >= r) {
      lazy[rt] += add_val;
      return;
    }
    int mid = (l + r) / 2;
    PushDown(rt);
    if (ul <= mid) Update(ul, ur, add_val, l, mid, rt << 1);
    if (ur > mid) Update(ul, ur, add_val, mid + 1, r, rt << 1 | 1);
  }

  int64_t Query(int pos, int l, int r, int rt) {
    if (l == r) return lazy[rt];
    PushDown(rt);
    int mid = (l + r) >> 1;
    if (pos <= mid) return Query(pos, l, mid, rt << 1);
    else return Query(pos, mid + 1, r, rt << 1 | 1);
  }
};
SegmentTree seg_tree;

void hash_x(int n, int d, std::vector<int64_t>* for_hash) {
  for (int i = 0; i < n; ++i) {
    for_hash->at(i) = a[i].x;
    for_hash->at(i + n) = (int64_t)a[i].x + 2 * d;
  }
  std::sort(for_hash->begin(), for_hash->end());
  for_hash->erase(std::unique(for_hash->begin(), for_hash->end()), for_hash->end());
}

int hash_find(int64_t v, const std::vector<int64_t>& for_hash) {
  return std::lower_bound(for_hash.begin(), for_hash.end(), v) - for_hash.begin() + 1;
}

int64_t solve(int n, int d, int p) {
  std::sort(a, a + n);
  std::vector<int64_t> for_hash(2 * n);
  hash_x(n, d, &for_hash);

  int64_t ans = 0;
  int seg_len = for_hash.size();
  
  for (int i = 0; i < n; ++i) {
    int x_hash = hash_find(a[i].x, for_hash);
    seg_tree.Update(x_hash, x_hash, a[i].h, 1, seg_len, 1);
    int64_t height = seg_tree.Query(x_hash, 1, seg_len, 1);
    int64_t use_bomb_num = (height + p - 1) / p;
    if (use_bomb_num <= 0) continue;
    ans += use_bomb_num;
    int r_hash = hash_find((int64_t)a[i].x + 2 * d, for_hash);
    seg_tree.Update(x_hash, r_hash, -use_bomb_num * p, 1, seg_len, 1);
  }
  return ans;
}

int main() {
  int n, d, p;
  std::cin >> n >> d >> p;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].x >> a[i].h;
  }
  std::cout << solve(n, d, p) << std::endl;
  return 0;
}
