#include <iostream>
#include <vector>

using namespace std;

int solve(int n)
{
	int F[n];
	F[1]=1,F[2]=1;
//	if(n==1||n==2) return F[n];
	for(int i=3;i<=n;i++){
		F[i]=F[i-1]+F[i-2];
	}
	return F[n];
}

int main()
{
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		v.push_back(solve(num)%1000);
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	return 0;
}