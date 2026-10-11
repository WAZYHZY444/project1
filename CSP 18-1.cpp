#include <iostream>

using namespace std;

bool isContainSeven(int x)
{
	while(x>0){
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	if(n<=0) return 0;
	int a[4]={0};
	int count=0;
	for(int i=1; ;i++){
		if(i%7==0||isContainSeven(i)){
			a[(i-1)%4]++;  //注意是先减去1再取模
		}else{
			count++;
		}
		if(count==n) break;
	}
	for(int i=0;i<4;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}