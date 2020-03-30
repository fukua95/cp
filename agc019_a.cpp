                                            
  //File Name: agc019_a.cpp
  //Created Time: 2017年10月15日 星期日 13时32分43秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL solve(LL q,LL h,LL s,LL d,LL n){
	if(q + q < h) h = q + q;
	if(h + h < s) s = h + h;
	if(s + s < d) d = s + s;
	n *= 4;
	LL res = n / 8 * d;
	n %= 8;
	res += n / 4 * s;
	n %= 4;
	res += n / 2 * h;
	n %= 2;
	res += n / 1 * q;
	return res;
}
int main(){
	LL q,h,s,d,n;
	cin >> q >> h >> s >> d >> n;
	cout << solve(q,h,s,d,n) << endl;
	return 0;
}
