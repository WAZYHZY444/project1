//分治算法

#include <iostream>

using namespace std;

double function(int a[],int astart,int aend,int b[],int bstart,int bend)
{
	int amid,bmid;
	int len=aend-astart+1;  //当前序列长度
	if(astart==aend&&bstart==bend){
		return (a[astart]+b[bstart])/2.0;
	}
	if(len==2){  //当两个序列分别只剩下两个元素
		return (max(a[astart],b[bstart])+min(a[aend],b[bend]))/2.0;
	}
	else{
		amid=(astart+aend)/2;
		bmid=(bstart+bend)/2;
		if(a[amid]==b[bmid]) return a[amid];
		
		if(a[amid]<b[bmid]){
			if(len%2==0){  //剩下偶数个序列
				//当当前长度为偶数时，mid会向前靠一个，所以a就要去掉包括中位数的后半部分，
				//b去掉不包含中位数的前半部分，这样就能保证下一层次两个序列长度相同
				return function(a,amid+1,aend,b,bstart,bmid);
			}else{
				return function(a,amid,aend,b,bstart,bmid);
			}
		}
		
		else{
			if(len%2==0){
				return function(a,astart,amid,b,bmid+1,bend);
			}else{
				return function(a,astart,amid,b,bmid,bend);
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	double result=function(a,0,n-1,b,0,n-1);
	cout<<result<<endl;
	return 0;
}