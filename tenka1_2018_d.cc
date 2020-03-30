#include <assert.h>

#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

vector<int> s[500];

int bs(int n) {
  int l = 1, r = n + 1;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if ((LL)mid * (mid - 1) <= n)
      l = mid;
    else
      r = mid;
  }
  return l;
}

void solve(int n) {
  int k = bs(n + n);
  if ((LL)k * (k - 1) != n + n) {
    cout << "No" << endl;
    return ;
  }
  int cur = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = i + 1; j <= k; ++j) {
      s[i].push_back(cur);
      s[j].push_back(cur++);
    }
  }
  assert(cur == n + 1);
  cout << "Yes" << endl;
  cout << k << endl;
  for (int i = 1; i <= k; ++i) {
    cout << k - 1 << " ";
    for (int j = 0; j < k - 1; ++j) {
      cout << s[i][j] << (j == k - 2 ? '\n' : ' ');
    }
  }
  return ;
}

int main() {
  int n;
  cin >> n;
  solve(n);
  return 0;
}
