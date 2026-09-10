#include <iostream>

using namespace std;

int dtower(int a[][5],int s[][5],int n)
{
	for(int i=0;i<n;i++){
		s[n-1][i]=a[n-1][i];
	}
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<=i;j++){
			s[i][j]=a[i][j]+max(s[i+1][j],s[i+1][j+1]);
		}
	}
	return s[0][0];
}

void trackBack(int a[][5],int s[][5],int i,int j,int n)
{
	if(i==n-1){
		cout<<i<<","<<j;   //打印最后一个点
		return;
	}
	cout<<i<<","<<j<<"->";  //递归内打印
	if(s[i][j]==a[i][j]+s[i+1][j]){
		trackBack(a,s,i+1,j,n);
	}else{
		trackBack(a,s,i+1,j+1,n);
	}
}

int main()
{
	int a[5][5]={{30,0,0,0,0},{23,21,0,0,0},{20,13,10,0,0},{7,12,10,22,0},{4,5,2,6,5}};
	int s[5][5]={0};
	int res=dtower(a,s,5);
	cout<<res<<endl;
	trackBack(a,s,0,0,5);
	return 0;
}