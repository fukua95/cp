#include <cstdio>
#include <algorithm>

const int P = (int)1e9 + 7;

int s[205];
int num[(int)1e5 + 5];
int64_t factorial[205];
int64_t comb[205][205];
int64_t f[(int)1e5 + 5];

void init(int n, int x) {
  std::sort(s, s + n);
  
  factorial[0] = 1;
  for (int i = 1; i <= n; ++i)
    factorial[i] = factorial[i - 1] * i % P;

  for (int i = 0; i <= n; ++i) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; ++j)
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % P;
  }

  for (int i = 0; i < n; ++i) {
    num[s[i]] = 1;
  }
  for (int i = 1; i <= x; ++i)
    num[i] += num[i - 1];
}

int solve(int n, int x) {
  init(n, x);
  for (int i = 0; i <= x; ++i) {
    if (i < s[0]) {
      f[i] = i;
      continue;
    }
    for (int j = 0; j < n; ++j) {
      if (s[j] > i)
        break;
      int tmp = num[i] - num[i % s[j]] - 1;
      f[i] += f[i % s[j]] * comb[num[i] - 1][tmp] % P * 
              factorial[tmp] % P;
      if (f[i] >= P)
        f[i] -= P;
    }
  }

//  for (int i = 0; i < n; ++i) 
//    printf("i = %d, f = %d\n", s[i], (int)f[s[i]]);
//  printf("x = %d f[x] = %d\n", x, (int)f[x]);

  int64_t res = f[x] * comb[n][n - num[x]] % P * factorial[n - num[x]] % P;
  return res;
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; ++i)
    scanf("%d", s + i);
  printf("%d\n", solve(n, x));
  return 0;
}
