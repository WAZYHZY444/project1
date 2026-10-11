#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++){
		int w,score;
		cin>>w>>score;
		sum+=w*score;
	}
	cout<<max(0,sum);
	return 0;
}