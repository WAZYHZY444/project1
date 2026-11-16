#include <iostream>

using namespace std;

int main()
{
	int k;
	cin>>k;
	int res[k][2];
	for(int i=0;i<k;i++){
		int u,o,n;
		cin>>u>>o>>n;
		double z=(n-u)*1.0/o;  //注意0.1的位置，不要写成了z=(n-u)/o*1.0
		z=(z+0.1)*10;
		int zhengshu=(int)z;
		double xiaoshu=z-zhengshu;
		res[i][0]=zhengshu;
		res[i][1]=(xiaoshu+0.1)*10;
	}
	for(int i=0;i<k;i++){
		cout<<res[i][0]<<" "<<res[i][1]<<endl;
	}
	return 0;
}