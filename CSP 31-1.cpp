#include <iostream>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int sx=0,sy=0;
	while(n--){
		int dx,dy;
		cin>>dx>>dy;
		sx+=dx;
		sy+=dy;
	}
	int res[m][2]={0};
	int k=0;
	for(int i=0;i<m;i++){  //注意这里不能写while(m--)，需要引入临时变量，否则后面在遍历输出res数组时索引错误
		int x,y;
		cin>>x>>y;
		res[k][0]=x+sx;
		res[k][1]=y+sy;
		k++;
	}
	for(int i=0;i<m;i++){
		cout<<res[i][0]<<" "<<res[i][1]<<endl;
	}
	return 0;
}