                                            
  //File Name: code_festival_2017_qualb_a.cpp
  //Created Time: 2017年10月10日 星期二 16时10分52秒
                                   
#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	size_t len = str.length();
	for(size_t i(0);i<len-8;++i)
		cout << str[i];
	cout << endl;
	return 0;
}
