#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	int n;
	while(cin>>n&&n!=0){
		v.push_back(n);
	}
	if(v.size()==0){
		cout<<0;
		return 0;
	}
	int res,mark=1;
	if(v[0]==1) res=1;
	
	if(v[0]==2) res=2;
	
	for(int i=1;i<v.size();i++){
		if(v[i]==1){
			res++;
			if(mark!=1) mark=1;  //当2不在连续就要把mark重置为1
		}
		if(v[i]==2){
			if(v[i]==v[i-1]) mark++;
			res+=2*mark;
		}
	}
	cout<<res;
	return 0;
}