#include <stdio.h>
int main()
{
	int a,b,n;
	scanf("%d %d",&a,&b);
	char c;
	scanf(" %c",&c);
	//当使用scanf读取字符时，在%c前加一个空格，可以跳过输入缓冲区中的空白字符（空格、换行符、制表符等）
	scanf("%d",&n);
	int arr[a][b];
	int i,j;
	if(n==1){
		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				printf("%c",c);
			}
			printf("\n");
		}
	}else if(n==0){
		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				if(i==0||i==a-1||j==0||j==b-1){
					printf("%c",c);
				}else{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}