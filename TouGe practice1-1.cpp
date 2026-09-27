#include <iostream>
#include <climits>

using namespace std;

bool isSeven(int n)
{
	while(n>0){
		int t=n%10;
		if(t==7){
			return true;
		}
		n/=10;
	}
	return false;
}

int main()
{
	int N;
	cin>>N;
	//注意：一定要避免死循环
	if(N<=0) return 0;
	
	int count=0;
	int num=0;
	int a[5]={0};
	for(int i=1; ;i++){
		if(i%7==0||isSeven(i)){
			a[(i-1)%5]++;
		}else{
			count++;
		}
		if(count==N){
			num=i;
			break;
		}
	}
	for(int i=0;i<5;i++){
		cout<<a[i]<<endl;
	}
	cout<<num;
	return 0;
}