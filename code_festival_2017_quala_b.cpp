                                            
  //File Name: code_festival_2017_quala_b.cpp
  //Created Time: 2017年09月30日 星期六 21时22分45秒
                                   
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	bool flag(false);
	for(int i(0);i<=n;++i){
		for(int j(0);j<=m;++j){
			if(m * i + n * j - 2 * i * j == k){
				flag = true;
				break;
			}
		}
	}
	if(flag) puts("Yes");
	else puts("No");
	return 0;
}
