#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool bracketCheck(string str)
{
	stack<char> st;
	for(int i=0;i<str.size();i++){
		if(str[i]=='('||str[i]=='{'||str[i]=='['){
			st.push(str[i]);
		}
		else if(str[i]==')'||str[i]=='}'||str[i]==']'){
			if(st.empty()) return false;
			char c=st.top();
			st.pop();
			if( (str[i]==')'&&c!='(') || (str[i]=='}'&&c!='{') || (str[i]==']'&&c!='[') ){
				return false;
			}
		}
	}
	return st.empty();	
}

int main()
{
	string str;
	cin>>str;
	bool result=bracketCheck(str);
	if(result){
		cout<<"括号匹配"<<endl;
	}else{
		cout<<"括号不匹配"<<endl;
	}
	return 0;
}