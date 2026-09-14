/*
	四柱汉诺塔问题（求最少移动次数）
		1.将a柱前n-k个盘子借助b、c移动到d（n-k个盘子四柱汉诺塔问题）
		2.将a柱剩余的k个盘子借助c移动到b（k个盘子三柱汉诺塔问题）
		3.将d柱前n-k个盘子借助a、c移动到b（n-k个盘子四柱汉诺塔问题）
	两个四柱汉诺塔问题，一个三柱汉诺塔问题,三柱汉诺塔问题的移动次数是2^n-1
*/

#include <iostream>

using namespace std;

int exp2(int k)
{
	return 1<<k;
}

int main()
{
	int n;
	cin>>n;
	int f[n+1];
	f[0]=0;
	f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=2*f[n-1]+1;   //初始化k=1
		for(int k=2;k<i;k++){
			int temp=2*f[n-k]+exp2(k)-1;
			f[i]=min(temp,f[i]);
		}
	}
	cout<<f[n]<<endl;
	return 0;
}