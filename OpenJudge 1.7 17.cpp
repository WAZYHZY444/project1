#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	
	vector<char> v1,v2;
	for(int i=0;i<s1.size();i++){
		if(s1[i]==' ') continue;
		v1.push_back(s1[i]);
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]==' ') continue;
		v2.push_back(s2[i]);
	}
	
	if(v1.size()!=v2.size()){
		cout<<"NO";
		return 0;
	}else{
		for(int i=0;i<v1.size();i++){
			if(v1[i]!=v2[i]&&abs(v1[i]-v2[i])!=32){
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}