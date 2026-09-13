#include <iostream>
#include <cmath>

using namespace std;

double a,b,c,d;

double calc(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}

void solve(double start,double end)
{
	double mid=(start+end)/2.0;
	double l=calc(start);
	double m=calc(mid);
	double r=calc(end);
	
	if(end-start<1e-7){
		printf("%.2f ",mid);
		return;
	}
	if(l*m<0){
		solve(start,mid);
	}
	if(m*r<0){
		solve(mid,end);
	}
	
}

int main()
{
	cin>>a>>b>>c>>d;
	for(int i=-100;i<100;i++){  //i不能等于100，因为x2=i+1
		double x1=i,x2=i+1;
		//左端点是根
		if(fabs(calc(x1))<1e-7){
			printf("%.2f ",x1);
			continue;
		}
		//区域内有根
		if(calc(x1)*calc(x2)<0){
			solve(x1,x2);
		}
	}
	//右端点100是根
	if(fabs(calc(100.0))<1e-7){
			printf("100");
		}
	return 0;
}