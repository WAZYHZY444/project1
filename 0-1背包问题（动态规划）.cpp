#include <iostream>

using namespace std;

int Knapsack(int n,int c,int w[],int v[],int x[])
{
	int m[n+1][c+1];
	for(int j=0;j<c+1;j++){
		m[0][j]=0;
	}
	
	//获取最优解
	for(int i=1;i<=n;i++){
		for(int j=0;j<=c;j++){
			if(w[i]<=j){
				m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
			}else{
				m[i][j]=m[i-1][j];
			}
		}
	}
	//获取最优解方法
	int j=c;
	for(int i=n;i>=1;i--){
		if(m[i][j]==m[i-1][j]){
			x[i]=0;
		}else{
			x[i]=1;
			j-=w[i];
		}
	}
	return m[n][c];
}

int main()
{
	int n,c;
	cout<<"请输入n和c的值：";
	cin>>n>>c;
	
	int w[n+1],v[n+1];  //w[n]存储物品重量，v[n]存储物品价值
	cout<<"请输入n个物品的重量和价值："<<endl;
	for(int i=0;i<n;i++){
		cin>>w[i]>>v[i];
	}
	
	int x[n]={0};  //存储最优选择方法
	int res=Knapsack(n,c,w,v,x);
	cout<<"最大价值="<<res<<endl;
	cout<<"最优解=";
	for(int i=0;i<n;i++){
		cout<<x[i]<<" ";
	}
	return 0;
}