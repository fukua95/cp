                                            
  //File Name: arc082_b.cpp
  //Created Time: 2017年10月01日 星期日 17时33分00秒
                                   
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
int p[MAXN];

int solve(const int n){
	int res(0),pre(0);
	for(int i(1);i<=n + 1;++i){
		if(p[i] != i){
			res += (i - pre) / 2;
			pre = i;
		}
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i(1);i<=n;++i)
		scanf("%d",p + i);
	printf("%d\n",solve(n));
	return 0;
}
