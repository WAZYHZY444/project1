#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int num=0;
	string res;
	for(int i=0;i<s.size();i++){
		int temp=num*10+(s[i]-'0');
		num=temp%13;
		res+=(temp/13+'0');
	}
	//去除前导零
	int i=0;
	while(res.size()>1&&res[i]=='0'){
		i++;
	}
	for(int k=i;k<res.size();k++){
		cout<<res[k];
	}
	cout<<endl;
	cout<<num<<endl;
	return 0;
}