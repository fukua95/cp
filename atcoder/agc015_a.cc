#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	LL a,b,n,ans(0);
	cin >> n >> a >> b;
	if(a <= b && n >= 2)
		ans = (b - a) * (n - 2) + 1;
	else if(a == b && n <= 2)
		ans = 1;
	cout << ans << endl;
	return 0;
}
