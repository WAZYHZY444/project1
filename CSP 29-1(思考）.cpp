#include <iostream>

using namespace std;

int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	int A=0;
	while(n--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int lx=max(0,x1);
		int ly=max(0,y1);
		int rx=min(a,x2);
		int ry=min(b,y2);
		if(lx<rx&&ly<ry) A+=(rx-lx)*(ry-ly);
	}
	cout<<A;
	return 0;
}