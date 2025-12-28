#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	char c1=' ';
	char c2='*';
	for(int i=1;i<=n;i++){   //i表示行号
		int C1=n-i;
		int C2=2*i-1;
		while(C1>0){
			printf("%c",c1);
			C1--;
		}
		while(C2>0){
			printf("%c",c2);
			C2--;
		}
		printf("\n");
	}
	return 0;
}