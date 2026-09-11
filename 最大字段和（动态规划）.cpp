#include <iostream>

using namespace std;

int maxSubSeq(int n,int a[],int& maxstart,int& maxend)
{
	int s=1,b=0;   //s记录起始位置，b记录子段和
	int sum=0;
	for(int i=0;i<n;i++){
		if(b>0){
			b+=a[i];
		}else{
			b=a[i];
			s=i;
		}
		if(b>sum){
			sum=b;
			maxstart=s;
			maxend=i;
		}
	}
	return sum;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int maxstart=0,maxend=0;
	int res=maxSubSeq(n,a,maxstart,maxend);
	cout<<res<<" "<<maxstart<<" "<<maxend<<endl;
	return 0;
}