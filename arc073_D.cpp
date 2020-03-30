                                            
  //File Name: arc073_D.cpp
  //Created Time: 2017年05月14日 星期日 15时06分26秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 103;
int f[MAXN][MAXN][MAXN * 3];
int w[MAXN],v[MAXN];
int solve(const int n,const LL m){
	memset(f,-1,sizeof f);
	f[0][0][0] = 0;
	for(int i(0);i<n;++i){
		for(int j(0);j<=i;++j){
			for(int k(0);k<=300;++k){
				if(f[i][j][k] == -1) continue;
				f[i + 1][j][k] = max(f[i + 1][j][k],f[i][j][k]);
				f[i+1][j+1][k+w[i+1]-w[1]] = max(f[i+1][j+1][k+w[i+1]-w[1]],f[i][j][k] + v[i+1]);
			}
		}
	}
	int res(0);
	for(int j(1);j<=n;++j){
		for(int k(0);k<=300;++k){
			if((LL)j * w[1] + k <= m && f[n][j][k] > res)
				res = f[n][j][k];
		}
	}
	return res;
}
int main(){
	int n;
	LL m;
	scanf("%d %lld",&n,&m);
	for(int i(1);i<=n;++i){
		scanf("%d %d",w + i,v + i);
	}
	printf("%d\n",solve(n,m));
	return 0;
}
