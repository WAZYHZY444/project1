#include <iostream>
#include <vector>

using namespace std;

int exp(int a,int n)
{
	int temp=a,res=1;
	int i=n;
	while(i>0){
		if(i%2){
			res=res*temp%10000;
		}
		i/=2;
		temp=temp*temp%10000;
	}
	return res;
}

int main()
{
	int k;
	cin>>k;
	vector<int> res;
	for(int i=0;i<k;i++){
		int n;
		cin>>n;
		res.push_back(exp(2011,n));
	}
	for(int s:res){
		cout<<s<<endl;
	}
	return 0;
}