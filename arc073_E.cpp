                                            
  //File Name: arc073_E.cpp
  //Created Time: 2017年05月14日 星期日 20时13分47秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 200000 + 5;
const int INF = (int)1e9 + 5;
pii a[MAXN];
set<pii> rem;
LL solve(const int n){
	sort(a,a + n);
	int b_mi(a[0].fir),b_ma(a[n - 1].fir);
	int r_mi(INF),r_ma(0);
	for(int i(0);i<n;++i){
		r_mi = min(r_mi,a[i].sec);
		r_ma = max(r_ma,a[i].sec);
	}
	LL res = (LL)(b_ma - b_mi) * (r_ma - r_mi);
	LL len = r_ma - b_mi;
	rem.insert(pii(a[0].sec,n));
	for(int i(1);i<n;++i)
		rem.insert(pii(a[i].sec,i));
	while(true){
		int tmp = (*rem.rbegin()).fir - (*rem.begin()).fir;
		res = min(res,len * tmp);
		auto cur = *rem.rbegin();
		rem.erase(cur);
		if(cur.sec == n) break;
		rem.insert(pii(a[cur.sec].fir,n));
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i(0);i<n;++i){
		scanf("%d %d",&a[i].fir,&a[i].sec);
		if(a[i].fir > a[i].sec) 
			swap(a[i].fir,a[i].sec);
	}
	printf("%lld\n",solve(n));
	return 0;
}
