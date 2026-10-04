#include <iostream>

using namespace std;

int main()
{
	int r,y,g;
	cin>>r>>y>>g;
	int n;
	cin>>n;
	int time=0;
	for(int i=0;i<n;i++){
		int k,t;
		cin>>k>>t;
		if(k==0||k==1) time+=t;
		if(k==2) time=time+t+g;
	}
	cout<<time;
	return 0;
}