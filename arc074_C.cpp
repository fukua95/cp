                                            
  //File Name: arc074_C.cpp
  //Created Time: 2017年06月17日 星期六 18时25分11秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 303;
const int P = (int)1e9 + 7;
LL f[MAXN][MAXN][MAXN];
vector<pii> que[MAXN];
void add(LL &x,LL y){
	x += y;
	if(x >= P) x -= P;
}
bool check(int i,int j,int k){
	int ma = max(i,max(j,k));
	int mi = min(i,min(j,k));
	int mid(-1);
	if(mi < i && i < ma) mid = i;
	else if(mi < j && j < ma) mid = j;
	else if(mi < k && k < ma) mid = k;
	if(mid == -1) mid = 0;
	for(auto cur:que[ma]){
		int l = cur.fir;
		int x = cur.sec;
		if(mi == 0 && mid == 0){
			if(x != 1) return false;
		}
		else{
			if(x == 3 && l <= mi) continue;
			if(x == 2 && mi < l && l <= mid) continue;
			if(x == 1 && mid < l && l <= ma) continue;
			return false;
		}
	}
	return true;
}
LL solve(const int n,const int m){
	f[0][0][0] = 1;
	for(int i(0);i<n;++i){
		for(int j(0);j<n;++j){
			if(j && (j == i)) continue;
			for(int k(0);k<n;++k){
				if(k && (k == i || k == j)) continue;
				if(!f[i][j][k]) continue;
				int nxt = max(i,max(j,k)) + 1;
				if(check(nxt,j,k)) 
					add(f[nxt][j][k],f[i][j][k]);
				if(check(i,nxt,k))
					add(f[i][nxt][k],f[i][j][k]);
				if(check(i,j,nxt))
					add(f[i][j][nxt],f[i][j][k]);
			}
		}
	}
	LL res(0);
	for(int i(0);i<n;++i){
		for(int j(0);j<n;++j){
			if(i && i == j) continue;
			LL tmp = f[i][j][n] + f[i][n][j] + f[n][i][j];
			tmp %= P;
			add(res,tmp);
		}
	}
	return res;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i(1),l,r,x;i<=m;++i){
		scanf("%d %d %d",&l,&r,&x);
		que[r].push_back(pii(l,x));
	}
	printf("%lld\n",solve(n,m));
	return 0;
}
