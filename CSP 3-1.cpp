#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	cout<<1;
	for(int i=1;i<n;i++){
		int count=1;
		for(int j=0;j<=i-1;j++){
			if(a[i]==a[j]){
				count++;
			}
		}
		cout<<" "<<count;
	}
	return 0;
}