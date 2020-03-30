                                            
  //File Name: agc001_a.cpp
  //Created Time: 2017年12月04日 星期一 16时11分07秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 202;
int a[MAXN];

int main(){
    int n;
    cin >> n;
    n += n;
    for(int i(0);i<n;++i)
        cin >> a[i];
    sort(a,a + n);
    int ans(0);
    for(int i(0);i+1<n;i+=2)
        ans += a[i];
    cout << ans << endl;
    return 0;
}
