#include <iostream>

using namespace std;

const int MAXN=20;

int n;  //顶点数
int m;  //颜色数目
int a[MAXN][MAXN];  //邻接矩阵
int x[MAXN]; //解向量x[i]顶点i的颜色
int sum;  //着色方案总数

bool ok(int k)
{
	for(int j=1;j<k;j++){
		if(a[j][k]&&x[j]==x[k]) return false;
	}
	return true;
}

void backTrack(int t)
{
	if(t>n){
		sum++;
	}else{
		for(int i=1;i<=n;i++){
			x[t]=i;
			if(ok(t)) backTrack(t+1);
		}
	}
}

int main()
{
	cin>>n>>m;
	//输入邻接矩阵
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sum=0;
	backTrack(1);
	if(sum==0) cout<<m<<"种颜色不能给地图上色"<<endl;
	else cout<<m<<"种颜色着色方案数为"<<sum<<endl;
	return 0;
}