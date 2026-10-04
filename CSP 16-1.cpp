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
	int M=max(a[0],a[n-1]);
	int m=min(a[0],a[n-1]);
	
	int mid=0;
	if(n%2!=0){
		mid=a[n/2];
		cout<<M<<" "<<mid<<" "<<m;
		return 0;
	}
	if(n%2==0&&(a[n/2-1]+a[n/2])%2==0){
		mid=(a[n/2-1]+a[n/2])/2;
		cout<<M<<" "<<mid<<" "<<m;
		return 0;
	}
	float Mid=0.0;
	if(n%2==0&&(a[n/2-1]+a[n/2])%2!=0)
	Mid=(a[n/2-1]+a[n/2])/2.0;
	printf("%d %.1f %d",M,Mid,m);
	return 0;
}