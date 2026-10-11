#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n,X,Y;
	cin>>n>>X>>Y;
	int a[n]={0};
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a[i]=(x-X)*(x-X)+(y-Y)*(y-Y);
	}
	int temp[n];
	for(int i=0;i<n;i++){
		temp[i]=a[i];
	}
	sort(a,a+n);
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			if(temp[j]==a[i]){
				cout<<j+1<<endl;
				temp[j]=-1;
				break;   //一次只输出一个，避免连续一次循环输出多个相同距离的编号
			}
		}
	}
	return 0;
}