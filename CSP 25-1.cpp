#include <iostream>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int a[k][2];
	for(int i=0;i<k;i++){
		cin>>a[i][0]>>a[i][1];
	}
	bool comp[n]={false};
	int count=0;
	for(int i=0;i<k;i++){
		if(comp[a[i][1]]==false&&a[i][1]!=0){
			count++;
			comp[a[i][0]]=true;
		}
		if(a[i][1]!=0&&comp[a[i][0]]==false){
			comp[a[i][0]]=true;
		}
	}
	cout<<count;
	return 0;
}