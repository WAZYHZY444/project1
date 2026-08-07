#include <iostream>

using namespace std;

int main()
{
	int M,N,X;
	cin>>M>>N>>X;
	while(N<=M&&X>0){
		int det=M/N;
		int loss=(M+N-1)/N;  //向上取整
		
		if(X<loss) break;
		
		X=X-loss;
		N=N+det;
	}
	cout<<N<<endl;
	return 0;
}