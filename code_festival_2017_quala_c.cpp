                                            
  //File Name: code_festival_2017_quala_c.cpp
  //Created Time: 2017年09月30日 星期六 21时42分35秒
                                   
#include <bits/stdc++.h>
using namespace std;
int a[26];
char str[105];

bool solve(int n,int m){
	if(n % 2 == 0 && m % 2 == 0){
		for(int i(0);i<26;++i){
			if(a[i] % 4)
				return false;
		}
	}
	else if(n % 2 && m % 2){
		int mod2(0),mod1(0);
		for(int i(0);i<26;++i){
			if(a[i] % 4 == 2) ++mod2;
			else if(a[i] % 4 == 1) ++mod1;
			else if(a[i] % 4 == 3) ++mod1,++mod2;
		}
		if(mod1 == 1 && mod2 <= (n / 2 + m / 2))
			return true;
		else 
			return false;
	}
	else{
		if(n % 2) swap(n,m);
		int mod2(0),mod13(0);
		for(int i(0);i<26;++i){
			if(a[i] % 4 == 2) ++mod2;
			else if(a[i] % 4 != 0) ++mod13;
		}
		if(mod13 == 0 && mod2 <= n / 2) 
			return true;
		return false;
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i(0);i<n;++i){
		scanf("%s",str);
		for(int j(0);j<m;++j)
			++a[str[j] - 'a'];
	}
	if(solve(n,m)) puts("Yes");
	else puts("No");
	return 0;
}
