                                            
  //File Name: arc074_A.cpp
  //Created Time: 2017年06月13日 星期二 14时56分12秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int INF = 0x3f3f3f3f;
int cal(int h,int w){
	if(h % 2 == 0) return h / 2;
	else{
		int x = ((LL)w * h - w - h + 2 * h - 2) / (2 * h - 1);
		return (LL)h * x - (LL)(w - x) * (h - 1) / 2;
	}
}
int main(){
	int h,w,ans;
	cin >> h >> w;
	if(h % 3 == 0 || w % 3 == 0)
		ans = 0;
	else{
		ans = min(h,w);
		ans = min(ans,cal(h,w));
		ans = min(ans,cal(w,h));
	}
	cout << ans << endl;
	return 0;
}
