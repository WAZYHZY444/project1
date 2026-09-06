#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<string> v;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		if(islower(str[0])){
			str[0]=toupper(str[0]);
		}
		for(int j=1;j<str.length();j++){
			if(isupper(str[j])){
				str[j]=tolower(str[j]);
			}
		}
		v.push_back(str);
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	return 0;
}