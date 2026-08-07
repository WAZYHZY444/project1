#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int count=0;
	for(int i=0;i<n;i++){
		int qian=a[i]/1000;
		int bai=a[i]/100%10;
		int shi=a[i]/10%10;
		int ge=a[i]%10;
		if((qian+bai+shi)<ge){
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}