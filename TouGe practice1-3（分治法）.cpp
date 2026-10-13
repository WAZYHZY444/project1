#include <iostream>
#include <climits>

using namespace std;

int solve(int left,int right,int stand,int a[])
{
	if(left>right) return 0;
	int shushou=right-left+1;  //全部竖着收
	int minH=INT_MAX;
	for(int i=left;i<=right;i++){
		minH=min(minH,a[i]);  //找到最矮的硬币堆
	}
	int hengshou=minH-stand;  //横着收
	
	//找到剩下的未被收完的硬币堆
	int i=left;
	while(i<=right){     //外层循环是为了找到所有的未收集完的硬币堆子序列
		if(a[i]==minH){  //当前子序列里只有高度大于等于min的硬币堆，小于min的在之前的递归轮次已经削减为0了
			i++;
			continue;
		}
		int newLeft=i;
		while(i<=right&&a[i]>minH){
			i++;
		}
		int newRight=i-1;
		hengshou+=solve(newLeft,newRight,minH,a);
	}
	return min(hengshou,shushou);
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int res=solve(0,n-1,0,a);
	cout<<res;
	return 0;
}