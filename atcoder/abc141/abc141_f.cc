#include <cstdio>

using LL = long long;
const int MAXN = (int)1e5;

LL a[MAXN];

struct LinearBasis {
  static const int MAXL = 64;
  LL a[MAXL];

  LinearBasis() {
    for (int i = 0; i < MAXL; ++i) a[i] = 0;
  }

  void Add(LL vec) {
    for (int j = MAXL - 1; j >= 0 && vec > 0; --j) {
      if (((vec >> j) & 1) == 0) continue;
      if (a[j] > 0) {
        vec ^= a[j];  // a[j]!=0,就用a[j]消去t的第j位的1
        continue;
      }
      for (int k = 0; k < j; ++k) {
        if ((vec >> k) & 1) vec ^= a[k];
      }
      for (int k = j + 1; k < MAXL; ++k) {
        if ((a[k] >> j) & 1) a[k] ^= vec;
      }
      a[j] = vec;
      break;
    }    
  }

  void Build(LL *vec_array, int len) {
    for (int i = 0; i < len; ++i) Add(vec_array[i]);
  }

  LL GetMax() {
    LL res = 0;
    for (int i = MAXL - 1; i >= 0; --i) {
      res ^= a[i];
    }
    return res;
  }
};

LL solve(int n) {
  LL xor_sum = 0;
  for (int i = 0; i < n; ++i) xor_sum ^= a[i];

  for (int i = 0; i < LinearBasis::MAXL; ++i) {
    if (((xor_sum >> i) & 1) == 0) continue;
    for (int j = 0; j < n; ++j) {
      if ((a[j] >> i) & 1) a[j] ^= (1LL << i);
    }
  }

  LinearBasis lb;
  lb.Build(a, n);
  LL lb_max = lb.GetMax();
  // printf("xor_sum = %lld\n", xor_sum);
  // printf("lb_max = %lld\n", lb_max);

  return lb_max * 2 + xor_sum;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", a + i);
  printf("%lld\n", solve(n));

  return 0;
}
