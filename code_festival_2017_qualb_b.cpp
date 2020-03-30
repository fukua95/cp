                                            
  //File Name: code_festival_2017_qualb_b.cpp
  //Created Time: 2017年10月10日 星期二 16时19分02秒
                                   
#include <bits/stdc++.h>
using namespace std;
map<int,int> a,b;

bool solve(){
	for(auto cur:b){
		int x(cur.first),y(cur.second);
		if(a.find(x) == a.end() || a[x] < y) 
			return false;
	}
	return true;
}
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i(0),u;i<n;++i){
		scanf("%d",&u);
		++a[u];
	}
	scanf("%d",&m);
	for(int i(0),u;i<m;++i){
		scanf("%d",&u);
		++b[u];
	}
	if(solve()) puts("YES");
	else puts("NO");
	return 0;
}
