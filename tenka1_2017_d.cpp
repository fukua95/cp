                                            
  //File Name: tenka1_2017_d.cpp
  //Created Time: 2017年10月13日 星期五 21时31分07秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 5;
LL a[MAXN],b[MAXN];

LL cal(const int n,const LL m){
	LL res(0);
	for(int i(0);i<n;++i){
		if((a[i] | m) == m)
			res += b[i];
	}
	return res;
}
LL solve(const int n,const LL m){
	LL res = cal(n,m);
	LL pre(m);
	for(int i(0);i<30;++i){
		if(m & (1LL << i)){
			LL tmp = pre ^ (1LL << i);
			LL cur = cal(n,tmp);
			if(cur > res)
				res = cur;
		}
		else
			pre |= (1LL << i);
	}
	return res;
}
int main(){
	int n;
	LL m;
	scanf("%d %lld",&n,&m);
	for(int i(0);i<n;++i)
		scanf("%lld %lld",a + i,b + i);
	printf("%lld\n",solve(n,m));
	return 0;
}
