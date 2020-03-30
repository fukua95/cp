                                            
  //File Name: agc015_B.cpp
  //Created Time: 2017年06月12日 星期一 21时51分31秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 1;
int a[MAXN];
char str[MAXN];
LL solve(){
	int n = strlen(str + 1);
	for(int i(1);i<=n;++i){
		if(str[i] == 'U')
			a[i] = 1;
		else
			a[i] = 0;
	}
	LL ans(0);
	for(int i(1);i<=n;++i){
		if(a[i] == 0) ans += n - 1 + n - i;
		else ans += n - 1 + i - 1;
	}
	return ans;
}
int main(){
	scanf("%s",str + 1);
	printf("%lld\n",solve());
	return 0;
}
