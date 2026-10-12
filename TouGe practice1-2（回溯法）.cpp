#include <iostream>
#include <climits>

using namespace std;

int n;
int count=0;
int curSum=0;
int maxPower=INT_MIN;

void backTrack(int i,int a[])
{
	if(i==n){
		if(count>0){
			maxPower=max(maxPower,curSum);
		}
		return;
	}
	//不选
	backTrack(i+1,a);
	//选
	int temp;
	if(count%2==0) temp=a[i];
	else temp=-a[i];
	curSum+=temp;
	count++;
	backTrack(i+1,a);
	curSum-=temp;  //回溯撤销
	count--;
}

int main()
{
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	backTrack(0,a);
	cout<<maxPower;
	return 0;
}