#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=20;

int n;
int c;  //背包总重量
int cw;   //当前已经装入背包的总重量
int cp;   //当前已经装入背包的总价值
int bestp;  //全局最优价值
int bestx[MAXN];  //保存最优解选择
int x[MAXN];      //当前路径选择

struct Item{
	int w,p;
	double pw;   //单位价值，为后面的限界函数（贪心算法）做准备
}item[MAXN];

//限界函数bound(i)：从i开始的价值上界
double bound(int i)
{
	int cleft=c-cw;  //背包剩余的容量
	int b=cp;   //当前拿到的价值
	while(i<=n&&item[i].w<=cleft){
		cleft-=item[i].w;
		b+=item[i].p;
		i++;
	}
	//装物品的一部分
	if(i<=n){
		b+=item[i].pw*cleft;
	}
	return b;  //返回最大价值
}

void backTrack(int i)
{
	if(i>n){
		bestp=cp;
		for(int k=1;k<=n;k++){
			bestx[k]=x[k];
		}
		return;
	}
	//左子树：选第i件
	if(cw+item[i].w<=c){
		cw+=item[i].w;
		cp+=item[i].p;
		x[i]=1;  //标记当前i物品被选择
		backTrack(i+1);
		cw-=item[i].w;  //回溯
		cp-=item[i].p;
		x[i]=0;
	}
	//右子树：不选第i件，限界剪枝
	if(bound(i+1)>bestp){
		x[i]=0;
		backTrack(i+1);
	}
}

int main()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>item[i].w>>item[i].p;
		item[i].pw=1.0*item[i].p/item[i].w;
	}
	//按单位价值pw降序排序（因为item下标是从1开始的，所以排序是注意起始结束位置）
	sort(item+1,item+n+1,[](Item a,Item b){return a.pw>b.pw;});
	
	cw=0;
	cp=0;
	bestp=0;
	backTrack(1);
	
	for(int i=1;i<=n;i++){
		if(bestx[i]==1){   
			cout<<"选择物品的重量："<<item[i].w<<'\t'<<"选择物品的价值："<<item[i].p<<endl;
		}
	}
	cout<<"选择的物品的最优总价值："<<bestp<<endl;
	
	return 0;
}