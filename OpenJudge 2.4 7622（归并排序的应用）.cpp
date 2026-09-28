#include <iostream>
#include <vector>

using namespace std;
long long sum=0;

vector<int> merge(const vector<int> &left,const vector<int> &right)
{
	vector<int> result;
	int i=0,j=0;
	while(i<left.size()&&j<right.size()){
		if(left[i]<right[j]){
			result.push_back(left[i++]);
		}
		else{
			result.push_back(right[j++]);
			sum+=left.size()-i;  //right[j]与left中下标i开始到末尾的所有元素都构成逆序对
		}
	}
	while(i<left.size()){
		result.push_back(left[i++]);
	}
	while(j<right.size()){
		result.push_back(right[j++]);
	}
	
	return result;
}

vector<int> solve(const vector<int> &a,int left,int right)
{
	if(left==right) return {a[left]};
	int mid=(left+right)/2;
	vector<int> leftPart=solve(a,left,mid);
	vector<int> rightPart=solve(a,mid+1,right);
	return merge(leftPart,rightPart);
}

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> res=solve(a,0,n-1);
	cout<<sum<<endl;
	return 0;
}