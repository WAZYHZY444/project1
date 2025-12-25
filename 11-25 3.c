#include <stdio.h>
int test1(int n)
{
	int sum=0;
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			sum+=i;
		}
	}
	return sum;
}
int test2(int n)
{
	int sum=0;
	for(int i=2;i<=n;i++){
		if(i%2==0){
			sum+=i;
		}
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n%2!=0){
		printf("%d\n",test1(n));
	}
	if(n%2==0){
		printf("%d\n",test2(n));
	}
	return 0;
}