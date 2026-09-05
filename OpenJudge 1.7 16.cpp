#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	
//	getline(cin,s);  //换行符作为结束标志，逗号和空格保留为普通字符
//	getline(cin,s,',');   //逗号作为结束标志，会读取空格，逗号丢弃
	//cin默认以空白字符（空格、制表符\t、换行符）作为分隔符和结束标志
	
	int n=min(s1.size(),s2.size());
	for(int i=0;i<n;i++){
		if(s1[i]!=s2[i]&&abs(s1[i]-s2[i])!=32){
			if(s1[i]<s2[i]){
				cout<<"<";
				return 0;
			}
			if(s1[i]>s2[i]){
				cout<<">";
				return 0;
			}
		}
	}
	
	if(s1.size()<s2.size()){
		cout<<"<";
	}
	else if(s1.size()>s2.size()){
		cout<<">";
	}
	else{
		cout<<"=";
	}
	return 0;
}	