#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> ops;
int a[3];

void consider_next_op(int idx, int n, int *u, int *v) {
  if (idx + 1 >= n) return;
  if (ops[idx] == "AB" && ops[idx + 1] == "BC" || 
      ops[idx] == "AC" && ops[idx + 1] == "BC" ||
      ops[idx] == "BC" && ops[idx + 1] == "AC") {
    std::swap(*u, *v);
  }
}

void solve(int n) {
  std::vector<int> ans;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    std::string op = ops[i];
    int u, v;
    if (op == "AB") u = 0, v = 1;
    else if (op == "AC") u = 0, v = 2;
    else u = 1, v = 2;
    
    if (a[u] == 0 && a[v] == 0) {
      ok = false;
      break;
    } else if (a[u] == a[v]) {
      consider_next_op(i, n, &u, &v);
    } else if (a[u] > a[v]) {
      std::swap(u, v);
    }
    ++a[u];
    --a[v];
    ans.emplace_back(u);
  }
  if (!ok) {
    std::cout << "No" << std::endl;
  } else {
    std::cout << "Yes" << std::endl;
    for (const auto& val : ans) {
      std::cout << (char)(val + 'A') << std::endl;
    }
  }
}

int main() {
  int n;
  std::cin >> n >> a[0] >> a[1] >> a[2];
  std::string op;
  for (int i = 0; i < n; ++i) {
    std::cin >> op;
    ops.emplace_back(op);
  }
  solve(n);
  return 0;
}
