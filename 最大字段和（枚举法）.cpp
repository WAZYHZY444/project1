#include <iostream>

using namespace std;

int maxSubSeq(int a[],int& maxstart,int& maxend,int n)
{
	int sum=0;
	for(int i=0;i<n;i++){
		int thisSum=0;
		for(int j=i;j<n;j++){
			thisSum+=a[j];
			if(thisSum>sum){
				sum=thisSum;
				maxstart=i;
				maxend=j;
			}
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
	int res=maxSubSeq(a,maxstart,maxend,n);
	cout<<res<<" "<<maxstart<<" "<<maxend<<endl;;
	return 0;
}