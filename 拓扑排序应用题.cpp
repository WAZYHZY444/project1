/*给出一个图的结构，输出其拓扑排序序列，要求在问等条件下，编号小的顶点在前
输入:
若干行整数，第一行有2个数，分别为顶点数v和弧数a，接下来有a行，每一行有2个数，分别是该条弧所关联的两个顶点编号
输出:
若干个空格隔开的顶点构成的序列（用小写字母）,如果存在环，输出发现环前的节点，再换行输出"none"

样例输入
6 8
1 2
1 3
1 4
3 2
3 5
4 5
6 4
6 5
*/

#include <iostream>

using namespace std;

const int MAXN=100;

int main()
{
	//只有一组数据，要是有多组就循环输入v,a，然后每组数据都要重新创建表、度等数组
	int v,a;
	cin>>v>>a;
	
	int graph[MAXN][MAXN]={0};
	int indegree[MAXN]={0};  //入度
	int visited[MAXN]={false};
	
	for(int i=0;i<a;i++){
		int from,to;
		cin>>from>>to;
		graph[from][to]=1; //表示两点之间是通路
		indegree[to]++;
	}
	
	int result[100];
	int count=0;
	
	//循环n次
	for(int i=0;i<v;i++){
		int minVertex=-1;
		
		//找编号最小的入度为0的未被访问的节点
		for(int j=1;j<=v;j++){
			if(!visited[j]&&indegree[j]==0){
				minVertex=j;
				break;
			}
		}
		//没找到，存在环
		if(minVertex==-1){
			for(int k=0;k<count;k++){
				if(k>0) cout<<" ";  //学习一下中间有空格末尾没有空格的处理
				cout<<"V"<<result[k];
			}
			cout<<"\n";
			cout<<"none"<<endl;
			return 0;
		}
		
		//输出当前顶点
		visited[minVertex]=true;
		result[count++]=minVertex;
		
		//减少入度
		for(int next=1;next<=v;next++){
			if(graph[minVertex][next]==1){
				indegree[next]--;
			}
		}
	}
	
	//输出完整拓扑序列
	for(int i=0;i<count;i++){
		if(i>0) cout<<" ";
		cout<<"V"<<result[i];
	}
	cout<<endl;
	
	return 0;
}