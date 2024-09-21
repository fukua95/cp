#include <cstdio>
#include <utility>
#include <algorithm>

using LL = long long;
const int MAXN = (int)1e5;

struct Clue {
  int u, v, c;
  Clue(int u = 0, int v = 0, int c = 0) : u(u), v(v), c(c) {}
  bool operator<(const Clue &other) {
    return c < other.c;
  }
}; 
Clue clues[MAXN];

// 需要2个并查集,一个判断点是不是在同一棵树，一个判断点是否在同一个环
int tree_rt[MAXN], tree_size[MAXN];
int cycle_rt[MAXN], cycle_size[MAXN];

int find_rt(int u, int *rt, int *size) {
  if (rt[u] == u) return u;
  int fa = find_rt(rt[u], rt, size);
  size[fa] += size[u];
  size[u] = 0;
  rt[u] = fa;
  return fa;
}

void union_rt(int u, int v, int *rt, int *size) {
  int u_rt = find_rt(u, rt, size);
  int v_rt = find_rt(v, rt, size);
  if (u_rt == v_rt) return;
  size[v_rt] += size[u_rt];
  size[u_rt] = 0;
  rt[u_rt] = v_rt;
}

bool construct_graph(int n, int clues_num) {
  for (int i = 0; i < n; ++i) {
    tree_rt[i] = cycle_rt[i] = i;
    tree_size[i] = cycle_size[i] = 1;
  }
  std::sort(clues, clues + clues_num);
  int pos = 0;
  for (; pos < clues_num && clues[pos].c == 0; ++pos) {
    union_rt(clues[pos].u, clues[pos].v, tree_rt, tree_size);
  }
  int tree_num = 0;
  for (int i = 0; i < n; ++i) {
    if (find_rt(i, tree_rt, tree_size) == i) ++tree_num;
  }
  bool can_have_cycle = tree_num > 2;

  for (; pos < clues_num && clues[pos].c == 1; ++pos) {
    int u_rt = find_rt(clues[pos].u, tree_rt, tree_size);
    int v_rt = find_rt(clues[pos].v, tree_rt, tree_size);
    if (u_rt == v_rt || !can_have_cycle) return false;
    union_rt(u_rt, v_rt, cycle_rt, cycle_size);
  }
  return true;
}

std::pair<LL, LL> calc_graph_edge_limit(int n, int m) {
  LL lower_limit = 0, upper_limit = 0;
  int can_in_cycle_num = 0;
  for (int i = 0; i < n; ++i) {
    if (find_rt(i, tree_rt, tree_size) == i) {
      lower_limit += tree_size[i] - 1;
      upper_limit += tree_size[i] - 1;
      ++can_in_cycle_num;
      if (find_rt(i, cycle_rt, cycle_size) == i) {
        if (cycle_size[i] == 2) lower_limit += 3;
        else if (cycle_size[i] > 2) lower_limit += cycle_size[i];
      }
    }
  }
  upper_limit += (LL)can_in_cycle_num * (can_in_cycle_num - 1) / 2;
  return std::make_pair(lower_limit, upper_limit);
}

bool solve(int n, int m, int clues_num) {
  bool can_construct_graph = construct_graph(n, clues_num);
  if (!can_construct_graph) return false;
  
  std::pair<LL, LL> limit = calc_graph_edge_limit(n, m);
  LL edge_lower_limit = limit.first;
  LL edge_upper_limit = limit.second;
  if (edge_lower_limit <= m && m <= edge_upper_limit) return true;
  return false;
}

int main() {
  int n, m, clues_num;
  scanf("%d %d %d", &n, &m, &clues_num);
  for (int i = 0, u, v, c; i < clues_num; ++i) {
    scanf("%d %d %d", &u, &v, &c);
    clues[i] = Clue(u, v, c);
  }
  if (solve(n, m, clues_num)) puts("Yes");
  else puts("No");
  return 0;
}
