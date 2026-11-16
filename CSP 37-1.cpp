#include <iostream>

int func(int b,int c,int x)
{
	return x*x+b*x+c;
}

using namespace std;

int main()
{
	int b,c,l,r;
	cin>>b>>c>>l>>r;
	int res=0;
	for(int i=l;i<=r;i++){
		if(i%2==0) res+=func(b,c,i);
	}
	res*=2;
	cout<<res;
	return 0;
}