//用分治算法实现归并排序

#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(const vector<int> &left,const vector<int> &right)
{
	int i=0,j=0;
	vector<int> result;
	while(i<left.size()&&j<right.size()){
		if(left[i]<right[j]){
			result.push_back(left[i++]);
		}else{
			result.push_back(right[j++]);
		}
	}
	
	//有可能n是奇数，left和right之间会相差一个（剩余）
	while(i<left.size()) result.push_back(left[i++]);
	while(j<right.size()) result.push_back(right[j++]);
	
	return result;
}

vector<int> mergeSort(const vector<int> &arr,int left,int right)
{
	if(left==right) return {arr[left]};  //返回包含1个元素的vector
	int mid=(left+right)/2;
	vector<int> leftPart=mergeSort(arr,left,mid);
	vector<int> rightPart=mergeSort(arr,mid+1,right);
	return merge(leftPart,rightPart);
}

int main()
{
	int n;
	cin>>n;
	
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> res=mergeSort(arr,0,n-1);
	for(int i=0;i<res.size();i++){
		if(i>0) cout<<" ";
		cout<<res[i];
	}
	cout<<endl;
	return 0;
}