#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

struct Item{
	int W,V;
	double rate;
};

bool compare(const Item& a,const Item& b)
{
	return a.rate>b.rate;
}

//k普通型的数量，c给普通型的咖啡数上限
int common(int k,int c,vector<int>& w,vector<int>& v,double& time)
{
	//创建一个(k+1)行(c+1)列的二维数组，所有元素初始化为0
	vector<vector<int>> arr(k+1,vector<int>(c+1,0));
	
	for(int i=1;i<=k;i++){
		for(int j=0;j<=c;j++){
			if(w[i-1]<=j){
				arr[i][j]=max(arr[i-1][j],arr[i-1][j-w[i-1]]+v[i-1]);
			}else{
				arr[i][j]=arr[i-1][j];
			}
		}
	}
	time=arr[k][c];
	
	//回溯算出在预算c内，普通型预算内剩余多少
	int j=c;
	for(int i=k;i>=1;i--){
		if(arr[i][j]!=arr[i-1][j]){
			j-=w[i-1];
		}
	}
	return j;
}

double flexible(vector<Item> it,int c)
{
	sort(it.begin(),it.end(),compare);
	
	double value=0.0;
	int remain=c;
	for(int j=0;j<it.size();j++){
		if(remain<=0) break;
		//消耗a杯咖啡
		if(it[j].W<=remain){
			value+=it[j].V;
			remain-=it[j].W;
		}else{
			//只消耗部分咖啡
			value+=it[j].rate*remain;
			remain=0;
		}
	}
	return value;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> w,v;
	vector<Item> it;
	int k=0;
	double base=0.0;
	for(int i=0;i<n;i++){
		int o,t,a,b;
		cin>>o>>t>>a>>b;
		base+=t;   //base存储的是所有原始完成项目所需要的时间（不包含缩短的时间）
		if(o==1){
			w.push_back(a);
			v.push_back(b);
		}
		if(o==0){
			it.push_back({a,b,(double)b/a});
		}
	}
	double ans=0.0;
	//循环来判断多少的咖啡用来普通型能使全局最优
	for(int c=0;c<=m;c++){
		double g=0.0;   //g用来存储普通型缩短的时间
		int rest_c=common(w.size(),c,w,v,g);  //返回的是普通型用完剩余的咖啡数（c里面剩下的）
		int totalRest=(m-c)+rest_c;
		double cur=g+flexible(it,totalRest);     //flexible返回的是灵活型缩短的时间
		ans=max(ans,cur);
	}

	printf("%.6f\n",base-ans);
	return 0;
}