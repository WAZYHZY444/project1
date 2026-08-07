#include <iostream>
#include <string>
#include <vector>

using namespace std;

//被2整除：末位是偶数
//被3整除：各位数字之和能被3整除
//被4整除：末两位能被4整除
//被5整除：末位是0或5
//被6整除：同时能被2和3整除
//被7整除：直接取模法
//被8整除：三位能被8整除
//被9整除：各位数字之和能被9整除

bool two(string s,int len){
	int num=s[len-1]-'0';
	return num%2==0;
}

bool three(string s,int len){
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=s[i]-'0';
	}
	return sum%3==0;
}

bool four(string s,int len){
	if(len==1){
		return (s[0]-'0')%4==0;
	}
	int num=(s[len-2]-'0')*10+(s[len-1]-'0');
	return num%4==0;
}

bool five(string s,int len){
	int num=s[len-1]-'0';
	return (num==0||num==5);
}

bool six(string s,int len){
	return (two(s,len)&&three(s,len));
}

bool seven(string s,int len){
	int num=0;
	for(int i=0;i<len;i++){
		num=(num*10+(s[i]-'0'))%7;
	}
	return num==0;
}

bool eight(string s,int len){
	if(len==1) return (s[0]-'0')%8==0;
	if(len==2){
		int num1=(s[len-2]-'0')*10+(s[len-1]-'0');
		return num1%8==0;
	}else{
		int num2=(s[len-3]-'0')*100+(s[len-2]-'0')*10+(s[len-1]-'0');
		return num2%8==0;
	}
}

bool nine(string s,int len){
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=s[i]-'0';
	}
	return sum%9==0;
}

int main()
{
	string s;
	cin>>s;
	int len=s.size();
	vector<int> v;
	if(two(s,len)) v.push_back(2);
	if(three(s,len)) v.push_back(3);
	if(four(s,len)) v.push_back(4);
	if(five(s,len)) v.push_back(5);
	if(six(s,len)) v.push_back(6);
	if(seven(s,len)) v.push_back(7);
	if(eight(s,len)) v.push_back(8);
	if(nine(s,len)) v.push_back(9);
	if(v.size()==0){
		cout<<"none"<<endl;
	}else{
		for(int i=0;i<v.size();i++){
			if(i>0) cout<<" ";
			cout<<v[i];
		}
		cout<<endl;
	}
	
	return 0;
}