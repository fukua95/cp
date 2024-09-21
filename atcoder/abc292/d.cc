#include <iostream>
#include <numeric>
#include <vector>

struct DSU {
  std::vector<int> parent;
  std::vector<int> size;

  DSU(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }
  int Root(int x) { return parent[x] == x ? x : parent[x] = Root(parent[x]); }
  void Merge(int x, int y) {
    x = Root(x);
    y = Root(y);
    if (x == y) return;
    if (size[x] < size[y]) std::swap(x, y);
    parent[y] = x;
    size[x] += size[y];
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> u(m), v(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> u[i] >> v[i];
    --u[i];
    --v[i];
  }

  DSU dsu(n);
  for (int i = 0; i < m; ++i) {
    dsu.Merge(u[i], v[i]);
  }

  std::vector<int> v_count(n, 0), e_count(n, 0);
  for (int i = 0; i < n; ++i) {
    ++v_count[dsu.Root(i)];
  }
  for (int i = 0; i < m; ++i) {
    ++e_count[dsu.Root(u[i])];
  }
  if (v_count == e_count)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}