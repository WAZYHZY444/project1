//将幂次用括号表示，即a^b-->a(b),完全表示为只由2、0、()表示
//如：73=2(6)+2(3)+2(0)=2(2(2)+2)+2(2+2(0))+2(0)
//分治算法

#include <iostream>
#include <string>

using namespace std;

string function(int n)
{
	if(n==0) return "0";
	if(n==1) return "2(0)";
	
	int temp=n,count=0;  //count用来记录n的二进制的位数（不包含前缀）
	while(temp>0){
		temp=temp>>1;  //（二进制）左移一位
		count++;
	}
	count--;
	
	string res;
	for(int i=count;i>=0;i--){
		if((n>>i)&1){  //二进制第i位的是1
			if(!res.empty()) res+="+";  //输出+号
			if(i==1) res+="2";          //如果是十位就直接表示为2，因为不能出现1
			else res+="2("+function(i)+")";
		}
	}
	return res;
}

int main()
{
	int n;
	cin>>n;
	string res=function(n);
	cout<<res<<endl;
	return 0;
}