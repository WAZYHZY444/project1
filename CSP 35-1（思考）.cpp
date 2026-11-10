#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v;
	while(n--){
		string s;
		cin>>s;
		bool alpha=false; //存在字母
		bool digit=false; //存在数字
		bool unique=false; //存在特殊字符
		int a[26]={0}; //存储小写字母
		int A[26]={0}; //存储大写字母
		for(int i=0;i<s.size();i++){
			if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')) alpha=true;
			if(s[i]>='0'&&s[i]<='9') digit=true;
			if(s[i]=='*'||s[i]=='#') unique=true;
			if(s[i]>='A'&&s[i]<='Z'){
				A[s[i]-'A']++;
			}
			if(s[i]>='a'&&s[i]<='z'){
				a[s[i]-'a']++;
			}
		}
		int tag=1;
		for(int i=0;i<26;i++){
			if(a[i]>2||A[i]>2){
				tag=0;
				break;
			}
		}
		if(tag&&alpha&&digit&&unique) v.push_back(2);
		else if(!tag&&alpha&&digit&&unique) v.push_back(1);
		else v.push_back(0);
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	return 0;
}