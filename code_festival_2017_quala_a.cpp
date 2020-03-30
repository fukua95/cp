                                            
  //File Name: code_festival_2017_quala_a.cpp
  //Created Time: 2017年09月30日 星期六 21时14分21秒
                                   
#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	if(str.length() >= 4 && str[0] == 'Y' && str[1] == 'A' && str[2] == 'K' && str[3] == 'I')
		puts("Yes");
	else
		puts("No");
	return 0;
}
