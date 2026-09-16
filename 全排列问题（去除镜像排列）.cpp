//去除镜像排列
//n个元素，保证每个·排列的首尾两元素满足小于或大于关系即可。
//先选定好首元素，再选定好尾元素，然后中间的n-2个元素进行全排列

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=20;

int n,sum=0;
int x[MAXN];

void backTrack(int t)
{
	if(t==n){
		for(int i=1;i<=n;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
		sum++;
		return;
	}else{
		for(int i=t;i<=n-1;i++){
			swap(x[i],x[t]);
			backTrack(t+1);
			swap(x[i],x[t]);
		}
	}
}

void demirror()
{
	sort(x+1,x+n+1);   //确保首元素小于尾元素
	for(int i=1;i<n;i++){
		swap(x[1],x[i]);   //确定首元素
		for(int j=i+1;j<=n;j++){
			swap(x[n],x[j]);  //确定尾元素
			backTrack(2);
			swap(x[n],x[j]);
		}
		swap(x[1],x[i]);
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	demirror();
	return 0;
}