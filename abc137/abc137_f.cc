#include <iostream>

const int MAXN = 3000;

int a[MAXN];
int poly_para[MAXN];   // Polynomial parameter, output data
int comb[MAXN][MAXN];  // comb[i][j] = C(i, j) % p

void init(int p) {
  for (int i = 0; i < p; ++i) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % p;
    }
  }
}

// Calc i^j
int pow(int i, int j, int p) {
  int res = 1;
  while (j > 0) {
    if (j & 1) res = res * i % p;
    i = i * i % p;
    j >>= 1;
  }
  return res;
}

// Calc 'poly_para'
void solve(int p) {
  init(p);
  for (int i = 0; i < p; ++i) {
    int cur = 0;
    for (int k = 0; k < p; ++k) {
      if (a[k] == 0) continue;
      cur += (-1) * pow(p - k, p - 1 - i, p);
    }
    cur = (cur % p + p) % p;
    poly_para[i] = cur * comb[p - 1][i] % p;
  }
  
  for (int i = 0; i < p; ++i) {
    poly_para[0] += a[i];
  }
  poly_para[0] = (poly_para[0] + p) % p;
}

int main() {
  int p;
  std::cin >> p;
  for (int i = 0; i < p; ++i) std::cin >> a[i];
  solve(p);
  for (int i = 0; i < p; ++i) std::cout << poly_para[i] << std::endl;
  return 0;
}
