#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN=20;

int n;
int M[MAXN][3];  //M[i][1]机器1处理第i个作业所需要的时间，M[i][2]机器2处理第i个作业所需要的时间
int x[MAXN];     //当前排列
int bestx[MAXN]; //最优排列
int f1;          //机器1累积时间
int f2[MAXN];    //f2[i] 前i个作业机器2完成时间
int f;           //当前总完成时间
int bestf;       //最优总时间

void backTrack(int t)
{
	if(t>n){
		for(int i=1;i<=n;i++){
			bestx[i]=x[i];
			bestf=f;
		}
	}else{
		for(int j=t;j<=n;j++){
			f1+=M[j][1];
			f2[j]=max(f2[t-1],f1)+M[j][2];
			f+=f2[t];
			//剪枝操作
			if(f<bestf){
				swap(x[t],x[j]);
				backTrack(t+1);
				swap(x[t],x[j]);
			}
			//回溯
			f1-=M[j][1];
			f-=f2[t];
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		x[i]=i;
		cin>>M[i][1]>>M[i][2];
	}
	f1=0;
	f=0;
	f2[0]=0;
	bestf=INT_MAX;
	backTrack(1);
	cout<<"最优调度顺序：";
	for(int i=1;i<=n;i++){
		cout<<bestx[i]<<" ";
	}
	cout<<endl;
	cout<<"最小完成总时间和为："<<bestf<<endl;
	return 0;
}