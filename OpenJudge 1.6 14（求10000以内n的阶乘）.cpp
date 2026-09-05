#include <iostream>
#include <vector>

using namespace std;

void multiply(vector<int>& a,int b)
{
	int key=0;
	for(int i=0;i<a.size()||key;i++){
		if(i==a.size()){
			a.push_back(0);
		}
		long long sum=(long long)a[i]*b+key;
		a[i]=sum%10;
		key=sum/10;
	}
	while(a.size()>1&&a.back()==0){
		a.pop_back();
	}
}

int main()
{
	vector<int> a;
	a.push_back(1);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i>1){
			multiply(a,i);	
		}
	}
	for(int i=a.size()-1;i>=0;i--){
		cout<<a[i];
	}
	cout<<endl;
	
	return 0;
}