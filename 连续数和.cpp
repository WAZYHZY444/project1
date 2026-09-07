//连续数和
/*
	n=a+a+1+a+2+a+3+……+a+k
	n=a*(k+1)+(1+k)*k/2=(a+k/2)*(1+k)=(2*a+k)*(1+k)/2
	a=(2*n/(1+k)-k)/2
	n>(k+1)^2/2
	k<根号(2n)-1  k的取值不大于根号(2n)
*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int mark=0;
	for(int k=1;k*k<=n;k++){
		mark=1;
		int a=(2*n/(1+k)-k)/2;
		if(a>0&&(2*a+k)*(1+k)/2==n){
			mark=0;
			for(int j=0;j<=k;j++){
				cout<<a+j<<" ";
			}
			break;
		}
	}
	if(mark){
		cout<<-1;
	}
	return 0;
}