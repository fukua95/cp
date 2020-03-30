                                            
  //File Name: tenka1_2017_c.cpp
  //Created Time: 2017年10月10日 星期二 23时22分28秒
                                   
#include <bits/stdc++.h>
using namespace std;

void solve(const int n){
	for(long long  i(1);i<=3500;++i){
		for(long long j(1);j<=i;++j){
			auto p = 4 * i * j - n * j - n * i;
			auto q = n * i * j;
			if(p > 0 && q % p == 0){
				long long k = q / p;
				cout << i << " " << j << " " << k << endl;
				return ;
			}
		}
	}
}
int main(){
	int n;
	cin >> n;
	solve(n);
	return 0;
}
