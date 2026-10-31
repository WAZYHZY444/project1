#include <iostream>
#include <queue>

using namespace std;

int solve(int w[],int C,int n)
{
	queue<int> q;
	q.push(0);     //w=0入队
	q.push(-1);   //-1为每层的结束标志
	int bestw=0;
	int i=1;
	
	while(true){
		int ew=q.front();  //ew=0
		q.pop();
		
		if(ew==-1){  //同层节点全部出队
			if(q.empty()) return bestw;
			q.push(-1);
			i++;  //进入下一层
			continue;
		}
			
		int wt=ew+w[i];
		if(wt<=C){
			if(wt>bestw) bestw=wt;
			if(i<n) q.push(wt);
		}
		//检查右儿子节点
		int r=0;
		for(int j=i+1;j<=n;j++){
			r+=w[j];
		}
		if(ew+r>bestw&&i<n){
			q.push(ew);
		}
	}
}

int main()
{
	int bestw=0,ew=0;
	int n,C;
	cin>>C>>n;
	int w[n+1];
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	bestw=solve(w,C,n);
	cout<<bestw<<endl;
	return 0;
}