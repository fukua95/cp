                                            
  //File Name: arc082_a.cpp
  //Created Time: 2017年10月01日 星期日 17时27分10秒
                                   
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
int a[MAXN];
int main(){
	int n;
	scanf("%d",&n);
	for(int i(1),u;i<=n;++i){
		scanf("%d",&u);
		++a[u];
		++a[u + 1];
		++a[u + 2];
	}
	int res(0);
	for(int i(0);i<MAXN;++i)
		res = max(res,a[i]);
	printf("%d\n",res);
	return 0;
}
