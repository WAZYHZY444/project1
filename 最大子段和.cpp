//分治算法求最大子段和

#include <iostream>

using namespace std;

int maxSubSeq(int* a,int left,int right)
{
	if(left==right){
		return a[left];
	}

	int mid=(left+right)/2;
	int max1=maxSubSeq(a,left,mid);
	int max2=maxSubSeq(a,mid+1,right);

//注意mid向左右扩展，不是一遇到负数就停止扩展，继续扩展有可能会得到更大的子段和
	int leftSum=0,maxLeftSum=a[mid];
	for(int i=mid;i>=left;i--){
		leftSum+=a[i];
		if(leftSum>maxLeftSum) maxLeftSum=leftSum;
	}
	
	int rightSum=0,maxRightSum=a[mid+1];
	for(int j=mid+1;j<=right;j++){
		rightSum+=a[j];
		if(rightSum>maxRightSum) maxRightSum=rightSum;
	}
	int max3=maxLeftSum+maxRightSum;
	
	return max(max3,max(max1,max2));
}

int main()
{
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int res=maxSubSeq(a,0,n-1);  //索引
	cout<<res<<endl;
	
	return 0;
}