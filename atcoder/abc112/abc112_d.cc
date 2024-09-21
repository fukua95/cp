#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> fact;

void factor(int m) {
  int a = sqrt(m + 0.5);
  for (int i = 1; i <= a; ++i) {
    if (m % i == 0) {
      fact.push_back(i);
      if (m / i != i)
        fact.push_back(m / i);
    }
  }
}

int solve(int n, int m) {
  int res = 1;
  factor(m);
  for(auto i : fact) {
    if (m / i >= n && i > res)
      res = i;
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  cout << solve(n, m) << endl;
  return 0;
}
