#include <iostream>

using namespace std;

int main()
{
	int n,a;
	cin>>n>>a;
	int m=0;
	for(int i=0;i<n;i++){
		double x,y;
		cin>>x>>y;
		if(x*x+y*y<=a*a) m++;
	}
	double res=4.0*m/n;
	cout<<res;
	return 0;
}