#include <iostream>
#include <cmath>

using namespace std;

int visited[105][105];  //标记数组，1表示访问过，0表示未访问
int mp[105][105];      //存储迷宫地图，1表示障碍物
int n,m;                //迷宫的行数和列数
int sx,sy,ex,ey;        //起点(sx,sy)和终点(ex,ey)坐标
int best=0x3f3f3f3f;    //记录最短路径长度，初始化为一个极大的数
//方向数组：分别代表向右、向左、向下、向上移动坐标的变化
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int x,int y,int s)
{
	if(x==ex&&y==ey){
		if(s<best) best=s;
		return;
	}
	
	if(s+abs(ex-x)+abs(ey-y)>=best) return;
	
	for(int i=0;i<4;i++){
		int cx=x+dx[i];
		int cy=y+dy[i];
		
		//边界检查
		if(cx<1||cx>n||cy<1||cy>m) continue;
		//有障碍物或已访问
		if(visited[cx][cy]||mp[cx][cy]==1) continue;
		
		visited[cx][cy]=1;
		dfs(cx,cy,s+1);
		visited[cx][cy]=0;  //回溯
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
	
	cin>>sx>>sy>>ex>>ey;
	visited[sx][sy]=1;  //起点标记为已访问
	dfs(sx,sy,0);
	cout<<best<<endl;
	return 0;
}