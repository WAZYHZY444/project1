#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	double sumMiu=0.0,sumSigema=0.0;
	for(int i=0;i<n;i++){
		double miu;
		cin>>miu;
		sumMiu+=miu;
	}
	for(int i=0;i<n;i++){
		double sigema;
		cin>>sigema;
		sumSigema+=sigema*sigema;
	}
	double x[k],f[k];
	for(int i=0;i<k;i++){
		cin>>x[i];
	}
	for(int i=0;i<k;i++){
		cin>>f[i];
	}
	double z=(m-sumMiu)/sqrt(sumSigema);
	int tag=0;
	for(int i=1;i<k;i++){
		if(x[i]>z){
			double mid=(x[i]+x[i-1])/2.0;
			if(z<=mid) tag=i-1;
			else tag=i;
			break;
		}
	}
	if(z>x[k-1]) tag=k-1;
	printf("%.3lf",f[tag]);
	return 0;
}