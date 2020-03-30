#include <cstdio>

const int MAXN = (int)2e5;

int p[MAXN];

double solve(int n, int k) {
  double cur_exp_val = 0.0;
  int index = 0;
  for (; index < k; ++index) {
    cur_exp_val += (1.0 + p[index]) / 2.0;
  }
  double max_exp_val = cur_exp_val;
  for (; index < n; ++index) {
    cur_exp_val += (1.0 + p[index]) / 2.0;
    cur_exp_val -= (1.0 + p[index - k]) / 2.0;
    if (cur_exp_val > max_exp_val) {
      max_exp_val = cur_exp_val;
    }
  }
  return max_exp_val;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p + i);
  }
  printf("%.6lf\n", solve(n, k));
  return 0;
}
