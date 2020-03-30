                                            
  //File Name: arc073_C.cpp
  //Created Time: 2017年05月14日 星期日 14时54分17秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL solve(const int n,const int t){
	LL res(0);
	int pre,now;
	scanf("%d",&pre);
	for(int i(2);i<=n;++i){
		scanf("%d",&now);
		if(now >= pre + t){
			res += t;
			pre = now;
		}
		else{
			res += now - pre;
			pre = now;
		}
	}
	res += t;
	return res;
}
int main(){
	int n,t;
	scanf("%d %d",&n,&t);
	printf("%lld\n",solve(n,t));
	return 0;
}
