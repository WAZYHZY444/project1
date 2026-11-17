#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int res1[n],res2[n];
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int pos=s.find('.');
		int a=0;
		for(int j=0;j<pos;j++){
			a=a*10+(s[j]-'0');
		}
		if((s[pos+1]-'0')>=0&&(s[pos+1]-'0')<=4){
			res1[i]=a;
			res2[i]=a;
		}
		else if((s[pos+1]-'0')==5){
			res1[i]=a+1;
			if(a%2==0) res2[i]=a;
			else res2[i]=a+1;
		}
		else{
			res1[i]=a+1;
			res2[i]=a+1;
		}
	}
	for(int i=0;i<n;i++){
		cout<<res1[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<res2[i]<<" ";
	}
	return 0;
}