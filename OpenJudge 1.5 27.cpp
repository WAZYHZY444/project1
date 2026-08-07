#include <iostream>

using namespace std;

int main()
{
	int K;
	cin>>K;
	double sum=0.0;
	int n=1;
	while(sum<=K){
		sum+=1.0/n;
		n++;
	}
	cout<<n-1<<endl;
	return 0;
}