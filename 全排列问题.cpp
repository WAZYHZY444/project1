#include <iostream>

using namespace std;

void permutation(int a[],int k,int n)  //k是其实位置，n是终点位置
{
	if(k==n-1){  //一个元素的子问题，此时排列已经确定，输出一个排列
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		return;
	}
	
	for(int i=k;i<n;i++){
		swap(a[i],a[k]);
		//求规模k+1~n的全排列问题
		permutation(a,k+1,n);
		//恢复原来的数组，使得下次递归前进行正确的交换
		swap(a[i],a[k]);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	permutation(a,0,n);
	return 0;
}