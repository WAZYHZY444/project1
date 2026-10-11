#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<string> v;
	int arr[n][2];
	char type[n];
	for(int i=0;i<n;i++){
		cin>>arr[i][0]>>arr[i][1]>>type[i];
	}
	
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		int mark=1;
		long long stand=a+arr[0][0]*b+arr[0][1]*c;
		for(int j=1;j<n;j++){
			long long com=a+arr[j][0]*b+arr[j][1]*c;
			//同号类别必须相同
			if(((com>0)&&(stand>0))||((com<0)&&(stand<0))){
				if(type[j]!=type[0]){
					mark=0;
					break;
				}
			}
			//异号类别必须不同
			if(((com>0)&&(stand<0))||((com<0)&&(stand>0))){
				if(type[j]==type[0]){
					mark=0;
					break;
				}
			}
		}
		if(mark==0) v.push_back("No");
		else v.push_back("Yes");
	}
	
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	return 0;
}