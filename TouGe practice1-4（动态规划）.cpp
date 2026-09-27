#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(int a[],int n)
{
	int totalSum=0;
	for(int i=0;i<n;i++){
		totalSum+=a[i];
	}
	if(totalSum%2!=0) return 0;
	
	int tar=totalSum/2;
	int temp[tar+1]={0};   //temp[i]表示能不能凑出和为i的子集，0表示不能，1表示能
	temp[0]=1;
	
	for(int i=0;i<n;i++){
		for(int j=tar;j>=a[i];j--){
			if(temp[j-a[i]]==1){
				temp[j]=1;
			}
		}
	}
	return temp[tar];
}

int main()
{
	int n;
	cin>>n;
	vector<string> v;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		int a[num];
		for(int j=0;j<num;j++){
			cin>>a[j];
		}
		sort(a,a+num);
		if(solve(a,num))  v.push_back("true");
		else v.push_back("false");
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	return 0;
}