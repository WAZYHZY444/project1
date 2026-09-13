#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

struct infor{
	int left,right;
};

//比较函数
bool compare(const infor& a,const infor& b)
{
	return a.left<b.left;
}

//分治法
infor solve(vector<infor>& a,int l,int r)
{
	if(l==r) return a[l];
	int mid=(r+l)/2;
	infor L=solve(a,l,mid);
	infor R=solve(a,mid+1,r);
	//避免上层拿到{INT_MAX,INT_MAX}还继续比较
	if(L.left==INT_MAX||R.left==INT_MAX) return {INT_MAX,INT_MAX};  //将INT_MAX作为失败哨兵，因为区间值有可能是-1
	if(R.left<=L.right){
		return {L.left,max(R.right,L.right)};
	}else{
		return {INT_MAX,INT_MAX};
	}
}

//线性扫描
void solve2(vector<infor>& a,int n)
{
	//a[0]来初始化L、R，此时的L已经是最小值了，只需要向右拓展R
	int L=a[0].left;
	int R=a[0].right;
	
	for(int i=1;i<n;i++){
		if(a[i].left<=R){
			R=max(R,a[i].right);
		}else{
			cout<<"no"<<endl;
			return;
		}
	}
	cout<<L<<" "<<R<<endl;
	return;
}

int main()
{
	int n;
	cin>>n;
	vector<infor> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].left>>a[i].right;
	}
	sort(a.begin(),a.end(),compare);
	
	infor res=solve(a,0,n-1);
	if(res.left==INT_MAX){
		cout<<"no"<<endl;
	}else{
		cout<<res.left<<" "<<res.right<<endl;
	}
	
	solve2(a,n);
	return 0;
}