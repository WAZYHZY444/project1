#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int count=0;
	long long x=2;
	while(count<n){
		int tag=1;
		for(int i=2;i*i<=x;i++){
			if(x%i==0){
				tag=0;
				break;
			}
		}
		if(tag==1){
			count++;
		}
		x++;
	}
	cout<<x-1;
	return 0;
}