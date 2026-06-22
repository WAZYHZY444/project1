#include <iostream>
#include <queue>

using namespace std;

const int MAX=100;

struct Point{
	int x,y;
	int step;  //从起点到该点的步长
};

struct PreNode{
	int x,y;
};

//记录每个点的前一个节点
PreNode prenode[MAX][MAX];

//方向数组：上、下、左、右
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int bfs(int maze[MAX][MAX],int n,int m,Point start,Point end)
{
	bool visited[MAX][MAX]={false};  //标记访问数组
	queue<Point> q;
	
	//起点初始化
	start.step=0;
	q.push(start);  //起点入队
	visited[start.x][start.y]=true;
	
	//BFS
	while(!q.empty()){
		Point cur=q.front();  //获取队首元素
		q.pop();
		
		//找到终点
		if(cur.x==end.x&&cur.y==end.y){
			return cur.step;
		}
		
		//未找到终点
		for(int i=0;i<4;i++){  //遍历四个方向
			int nx=cur.x+dx[i];
			int ny=cur.y+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&maze[nx][ny]==0){
				visited[nx][ny]=true;
				
				Point next;
				next.x=nx;
				next.y=ny;
				next.step=cur.step+1;
				q.push(next);
			}
		}
	}
	return -1;
}

int main()
{
	int n,m;
	cin>>n>>m;
	int maze[MAX][MAX];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>maze[i][j];
		}
	}
	Point start,end;
	//起点
	start.x=0;
	start.y=0;
	//终点
	end.x=n-1;
	end.y=m-1;
	
	int steps=bfs(maze,n,m,start,end);
	cout<<steps;
	return 0;
}