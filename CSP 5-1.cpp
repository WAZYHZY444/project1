#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int i=1,count=1;
	while(i<n){
		if(a[i]!=a[i-1]){
			count++;
		}
		i++;
	}
	cout<<count<<endl;
	return 0;
}