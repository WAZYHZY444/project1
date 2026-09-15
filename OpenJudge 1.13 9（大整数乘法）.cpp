#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void multiply(string s1,string s2)
{
	if(s1=="0"||s2=="0"){
		cout<<"0"<<endl;
		return;
	}
	
	int n=s1.size(),m=s2.size();
	int len=n+m;
	vector<int> res(len,0);
	//倒序存储
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int sum=res[i+j]+(s1[i]-'0')*(s2[j]-'0');
			res[i+j]=sum%10;  //当前位
			res[i+j+1]+=sum/10;  //进位给下一位
		}
	}
	
	//跳过前导零
	while(len>1&&res[len-1]==0){
		len--;
	}
	
	for(int i=len-1;i>=0;i--){
		cout<<res[i];
	}
	cout<<endl;
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	multiply(s1,s2);
	return 0;
}