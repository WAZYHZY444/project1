//（贪心算法）给定一个正整数，求最小正整数res,满足两个条件：res各数位的数字互不相同，且各位数字之和等于s

#include <iostream>

using namespace std;

int main()
{
	int s;
	cin>>s;
	int res=0,x=1;
	int temp=9;
	while(s>temp){
		//大的数字放低位，小的数字放高位
		res+=temp*x;
		s-=temp;
		x*=10;
		temp--;
	}
	res+=s*x;
	cout<<res<<endl;
	return 0;
}