                                            
  //File Name: arc074_B.cpp
  //Created Time: 2017年06月13日 星期二 15时50分50秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 300000 + 5;
LL a[MAXN];
pii b[MAXN];
int is[MAXN]; //表示第i个数目前属于哪里：1大的，0候选，2小的
bool cmp(pii x,pii y){
	if(x.fir == y.fir) return x.sec < y.sec;
	return x.fir > y.fir;
}
LL solve(const int n){
	LL res(0),big(0),small(0);
	sort(b + 1,b + n + n + 1,cmp);
	for(int i(1);i<=n;++i){
		is[b[i].sec] = 1;
		big += b[i].fir;
	}
	priority_queue<pii> que; //用来保存目前的候选数
	for(int i(n+1);i<=2 * n;++i){
		is[b[i].sec] = 0;
		que.push(b[i]);
	}
	priority_queue<int> rem;  //用来保存目前的后面的前n小个数
	for(int i(n + n + 1);i<=3 * n;++i){
		is[i] = 2;
		small += a[i];
		rem.push(a[i]);
	}
	res = big - small;
	for(int i(n + n);i>n;--i){
		if(is[i] == 1){
			big -= a[i];
			pii tmp;
			while(!que.empty()){
				tmp = que.top();
				que.pop();
				if(is[tmp.sec]) continue;
				else break;
			}
			big += tmp.fir;
			is[tmp.sec] = 1;
		}
		is[i] = 2;
		LL cur = rem.top();
		if(cur > a[i]){
			rem.pop();
			small += a[i] - cur;
			rem.push(a[i]);
		}
		res = max(res,big - small);
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i(1);i<=3*n;++i){
		scanf("%d",a + i);
		b[i] = pii(a[i],i);
	}
	printf("%lld\n",solve(n));
	return 0;
}

