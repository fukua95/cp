#include <iostream>

using namespace std;

int main() {
  int n,t;
  scanf("%d %d",&n,&t);
  int ans = 1000 + 1;
  for (int i = 1, u, v; i <= n; ++i) {
    scanf("%d %d",&u,&v);
    if (v <= t && u < ans)
     ans = u; 
  }
  if (ans == 1001) 
    printf("TLE\n");
  else
    printf("%d\n", ans);
  return 0;
}
