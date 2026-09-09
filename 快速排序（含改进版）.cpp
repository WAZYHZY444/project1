int Partition(int arr[],int low,int high){
	int pivot=arr[low];     //第一个元素作为枢轴
	while(low<high){
		while(low<high&&arr[high]>=pivot){
			high--;   //左移high直到遇到比枢轴小的元素
		}
		arr[low]=arr[high];

		while(low<high&&arr[low]<=pivot){
			low++;   //右移low直到遇到比枢轴大的元素
		}
		arr[high]=arr[low];
	}
	arr[low]=pivot;
	return low;
}

void QuickSort(int arr[],int low,int high){
	if(low<high){
		int pivotpos=Partition(arr,low,high);
		QuickSort(arr,low,pivotpos-1);       //划分左子表
		QuickSort(arr,pivotpos+1,high);      //划分右子表
	}
}

//快速排序改进版：当数组有大量重复元素时，可以大大提高效率

#include <iostream>

using namespace std;

void threep(int a[],int &p,int &r)
{
	int temp=a[p];
	int k=p+1;
	while(k<=r){
		if(a[k]==temp) k++;
		else if(a[k]<temp) swap(a[k++],a[p++]);
		else swap(a[r--],a[k]);
	}
}

void quickSort(int a[],int low,int high)
{
	if(low<high){
		int llow=low,hhigh=high;
		threep(a,llow,hhigh);
		quickSort(a,low,llow-1);
		quickSort(a,hhigh+1,high);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	//测试当a[]={5,7,5,2,5,8}时，第一次运行threep函数后，数组序列变为{2,5,5,5,8,7}，p=1，r=3
	//此时{2}为一个子序列，{8,7}为一个子序列，重复数组的都已确定，大大提高了效率
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int p=0,r=n-1;
	quickSort(a,p,r);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}