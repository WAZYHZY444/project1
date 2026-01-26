#include <stdio.h>
int is_prime(int x)
{
	int mark=1;      //是质数
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			mark=0;  //不是质数
			break;
		}
	}
	return mark;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=4;i<=N;i+=2){
		int p=2,q=i-p;
		while(p<=q){
			if(is_prime(p)&&is_prime(q)){
				printf("%d=%d+%d\n",i,p,q);
				break;
			}
			p++;
			q--;
		}
	}
	return 0;
}