#include <iostream>

using namespace std;

//int main()
//{
//	int n;
//	cin>>n;
//
//	int count=0;
//	for(int i=0;i<n;i++){
//		int num;
//		cin>>num;
//		int s0=0;
//		int s1=0;
//		while(num>0){
//			int res=num%2;
//			num=num/2;
//			if(res==0) s0++;
//			if(res==1) s1++;
//		}
//		if(s0==s1) count++;
//	}
//	cout<<count;
//}

int main()
{
	int n;
	cin>>n;
	
	int count=0;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		int s0=0;
		int s1=0;
		while(num>0){
			//按位与运算规则：只有两个对应位都是1时，结果才为1；否则为0
			if(num&1==1) s1++;
			else s0++;
			num/=2;
		}
		if(s0==s1) count++;
	}
	cout<<count;
}