#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

struct Item{
	int W,V;
	double radio;
};

bool compare(const Item& a,const Item& b)
{
	return a.radio>b.radio;
}

int common(int k,int m,vector<int>& w,vector<int>& v,double& time)
{
	vector<vector<int>> arr(k+1,vector<int>(m+1,0));
	
	for(int i=1;i<=k;i++){
		for(int j=0;j<=m;j++){
			if(w[i-1]<=j){
				arr[i][j]=min(arr[i-1][j],arr[i-1][j-w[i-1]]+v[i-1]);
			}else{
				arr[i][j]=arr[i-1][j];
			}
		}
	}
	time=arr[k][m];
	
	//回溯求剩余容量
	int j=m;
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
	for(int j=0;j<it.size();j++){
		if(c<=0) break;
		//消耗a杯咖啡
		if(it[j].W<=c){
			value+=it[j].V;
			c-=it[j].W;
		}else{
			//只消耗部分咖啡
			value+=it[j].radio*c;
			c=0;
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
		int rest=common(w.size(),c,w,v,g);  //返回的是普通型用完剩余的咖啡数
		double cur=g+flexible(it,rest);     //flexible返回的是灵活型缩短的时间
		ans=max(ans,cur);
	}

	printf("%.6f\n",base-ans);
	return 0;
}