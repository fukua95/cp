                                            
  //File Name: agc014_A.cpp
  //Created Time: 2017年05月14日 星期日 00时20分41秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL a,b,c;
int solve(){
	if((a & 1) || (b & 1) || (c & 1)) return 0;
	int ma = 5000000;
	LL aa,bb,cc;
	for(int i(1);i<=ma;++i){
		aa = b / 2 + c / 2;
		bb = a / 2 + c / 2;
		cc = a / 2 + b / 2;
		a = aa,b = bb,c = cc;
		if((a & 1) || (b & 1) || (c & 1))
			return i;
	}
	return -1;
}
int main(){
	cin >> a >> b >> c;
	cout << solve() << endl;
	return 0;
}
