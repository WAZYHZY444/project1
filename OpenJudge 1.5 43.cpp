#include <iostream>

using namespace std;

bool isFrame(int x)
{
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	for(int i=2;i<=n/2;i++){   //注意索引取值范围
		if(n%i==0&&isFrame(i)&&isFrame((n/i))){
			cout<<n/i<<endl;
			break;
		}
	}
	return 0;
}