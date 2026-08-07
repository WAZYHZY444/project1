#include <iostream>
#include <string>

using namespace std;

string s1,s2;
int a[201],b[201],c[201];

int main()
{
	int la,lb,lc;
	cin>>s1>>s2;
	
	la=s1.size();
	lb=s2.size();
	
	for(int i=0;i<la;i++){
		a[la-i]=s1[i]-'0';
	}
	for(int i=0;i<lb;i++){
		b[lb-i]=s2[i]-'0';
	}
	
	lc=max(la,lb);
	for(int i=1;i<=lc;i++){
		if(a[i]<b[i]){
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
	}
	
	//去除前导零
	while(lc>1&&c[lc]==0){
		lc--;
	}
	
	//输出结果
	for(int i=lc;i>=1;i--){
		cout<<c[i];
	}
	cout<<endl;
	return 0;
}