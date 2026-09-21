#include <iostream>

using namespace std;

const int MAXN=20;

int n,c;     //物品数量和背包重量
int bestp;   //全局最优价值
int bestx[MAXN];  //保存最优解选择
int x[MAXN];      //当前路径选择

struct Item{
	int w,p;	
}item[MAXN];

void dfs(int i,int cw,int cp)
{
	if(i==n+1){
		if(cp>bestp){
			bestp=cp;
			for(int k=1;k<=n;k++){
				bestx[k]=x[k];
			}
		}
		return;
	}
	if(cw+item[i].w<=c){
		x[i]=1;
		dfs(i+1,cw+item[i].w,cp+item[i].p);
	}
	x[i]=0;
	dfs(i+1,cw,cp);
}

int main()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>item[i].w>>item[i].p;
	}
	int cw=0,cp=0;   //当前已经装入背包的总质量和价值
	bestp=0;
	dfs(1,cw,cp);
	
	for(int i=1;i<=n;i++){
		if(bestx[i]==1){
			cout<<"选择的物品重量："<<item[i].w<<'\t'<<"选择的物品价值："<<item[i].p<<endl;
		}
	}
	cout<<"选择的物品的最大价值："<<bestp<<endl;
	return 0;
}