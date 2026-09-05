#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	if(s1==s2){
		cout<<s1<<" is substring of "<<s2;
		return 0;
	}
	string maxs,mins;
	int maxlen,minlen;
	
	if(s1.size()>s2.size()){
		maxs=s1;
		mins=s2;
		maxlen=s1.size();
		minlen=s2.size();
	}
	else{
		maxs=s2;
		mins=s1;
		maxlen=s2.size();
		minlen=s1.size();
	}
	
	for(int i=0;i<=maxlen-minlen;i++){
		int mark=1;
		for(int j=0;j<minlen;j++){
			if(maxs[i+j]!=mins[j]){
				mark=0;
				break;
			}
		}
		if(mark){
			cout<<mins<<" is substring of "<<maxs;
			return 0;
		}
	}
	cout<<"No substring";
	return 0;
}