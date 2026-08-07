#include <iostream>
#include <string>

using namespace std;

bool canDivide(string s,int divisor)
{
	int num=0;
	for(int i=0;i<s.size();i++){
		num=(num*10)+(s[i]-'0')%divisor;
	}
	return num==0;
}

int main()
{
	string s;
	cin>>s;
	bool div1=canDivide(s,7);
	if(div1) cout<<"s能被7整除"<<endl;
	else cout<<"s不能被7整除"<<endl;
	return 0;
}