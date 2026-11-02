//算法描述
/*
算法开始时创建一个最小堆,用于表示活结点优先队列。
堆中每个活结点的优先级（下界）为：cc+lcost。cc为出发城市到当前城市的路程(或费用),lcost 是当前顶点(当前城市)最小出边+剩余顶点(城市)最小出边和(禁忌除外)。

每次从优先队列中取出一个活结点成为扩展结点(s层结点),当s=n-2时,扩展出的结点是排列树中某个叶子结点的父结点。
如该叶结点相应一条可行回路且费用小于当前最优解 bestc,则将该结点插入到优先队列中,否则舍去该结点
当s<n-2时，产生当前扩展结点的所有儿子结点。计算可行儿子结点的优先级cc+lcost及相关信息。当cc+lcost<bestc时，将这个可行儿子结点插入到活结点优先队列中。

该扩展过程一直持续到优先队列中取出的活结点是一个叶子结点为止。

最小出边（禁忌除外）的解释：
对于刚扩展出的顶点，其前已选的所有顶点是禁忌的（不能选）
对于未扩展出的顶点，其前已选的（顶点1除外）的顶点是禁忌的
*/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN=100;
const int INF=INT_MAX;

int n;  //城市数量
int g[MAXN][MAXN];  //图的邻接矩阵
int bestc=INF;

//活节点结构体
struct Node{
	int s;  //层数（已访问的城市-1）
	int cc;  //当前路径实际花费
	int lcost;  //剩余路径下界
	int priority;  //优先级=cc+lcost
	vector<int> path;  //记录当前路径
	
	bool operator < (const Node& other)const{
		return priority>other.priority;   //优先级小的先出队
	}
};

priority_queue<Node> pq;

//计算lcost
int calcCost(int current_city,int s,const vector<int>& path)
{
	int lcost=0;
	//计算当前城市的最小出边
	int min_out_current=INF;
	for(int i=0;i<n;i++){
		if(i==current_city) continue;
		bool visited=false;
		//path里面存储的是已经走过的城市了，相当于i在path中搜索判断i号城市是否被访问过，如果没有访问过就可以考虑作为下一个访问城市
		for(int v=0;v<path.size();v++){
			if(v==i){
				visited=true;
				break;
			}
		}
		if(!visited){
			min_out_current=min(min_out_current,g[current_city][i]);
		}
	}
	lcost+=min_out_current;
	
	//计算剩余未访问城市的最小出边
	for(int j=0;j<n;j++){
		//如果u是当前城市，或者j已经访问过，则跳过
		if(j==current_city) continue;
		bool visited=false;
		for(int v=0;v<path.size();v++){
			if(path[v]==j){
				visited=true;
				break;
			}
		}
		if(!visited) continue;
		
		//执行下面的代码的j是未访问城市，计算它的最小出边
		int min_out_j=INF;
		for(int u=0;u<n;u++){  //u是j出边要去的城市
			if(j==u) continue;
			//对于未扩展的节点，不能提前回到起点，除非所有节点都访问完了
			if(u==0&&s<n-1) continue;  //当前没有到达叶子节点却出边想要去起点0号城市（省去）
			
			//不能去已经访问过的城市
			bool u_visited=false;
			for(int city=0;city<path.size();city++){
				if(path[city]==u){
					u_visited=true;
					break;
				}
			}
			if(!u_visited){
				min_out_j=min(min_out_j,g[j][u]);
			}
		}
		if(min_out_j!=INF) lcost+=min_out_j;
	}
	return lcost;
}

void TSP()
{
	Node root;
	root.s=0;
	root.cc=0;
	root.path.push_back(0);  //从0号城市出发
	root.lcost=calcCost(0,root.s,root.path);
	root.priority=root.cc+root.lcost;
	pq.push(root);
	
	while(!pq.empty()){
		Node node=pq.top();
		pq.pop();
		
		//剪枝：如果当前下界已经>=当前最优解，直接丢弃
		if(node.priority>=bestc) continue;
		
		int u=node.path.back();  //最后一个入队的城市就是当前城市
		
		//情况1：当node.s==n-2时，直接产生最终回路，不再入队
		if(node.s==n-2){
			//找到唯一剩下的那个城市
			int last_city=-1;
			for(int i=0;i<n;i++){
				bool visited=false;
				for(int city=0;city<node.path.size();city++){
					if(node.path[city]==i){
						visited=true;
						break;
					}
				}
				if(!visited){
					last_city=i;
					break;
				}
			}
			
			//构造回路：当前城市->最后城市->起点(0)
			int final_cost=node.cc+g[u][last_city]+g[last_city][0];
			if(final_cost<bestc){
				bestc=final_cost;
			}
			continue;  //node.s==n-2就不需要再加入节点了
		}
		
		//情况2：node.s<n-2
		for(int v=0;v<n;v++){
			bool visited=false;
			for(int city=0;city<node.path.size();city++){
				if(node.path[city]==v){
					visited=true;
					break;
				}
			}
			if(!visited){
				Node child;
				child.s=node.s+1;
				child.cc=node.cc+g[u][v];
				child.path=node.path;
				child.path.push_back(v);
				
				child.lcost=calcCost(v,child.s,child.path);
				child.priority=child.cc+child.lcost;
				
				if(child.priority<bestc){
					pq.push(child);
				}
			}
		}
	}
}

int main()
{
	n=4;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			g[i][j]=(i==j)?INF:0;
		}
	}
	
	g[0][1]=2;g[1][0]=2;
    g[0][2]=6;g[2][0]=6;
    g[0][3]=5;g[3][0]=5;
    g[1][2]=4;g[2][1]=4;
    g[1][3]=8;g[3][1]=8;
    g[2][3]=3;g[3][2]=3;
    
    TSP();
    cout<<"最短回路长度为：" <<bestc<<endl;
    return 0;
}