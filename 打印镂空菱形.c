#include <stdio.h>
int main()
{
	int n;
	char ch1=' ';
	char ch2='*';
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int CH1=n-i;
		int CH2=2*i-3;
		while(CH1>0){
			printf("%c",ch1);
			CH1--;
		}
		printf("%c",ch2);
		if(CH2>0){
			while(CH2>0){
				printf("%c",ch1);
				CH2--;
			}
			printf("%c",ch2);
		}
		printf("\n");
	}
	
	for(int i=(n-1);i>0;i--){
		int CH1=n-i;
		int CH2=2*i-3;
		while(CH1>0){
			printf("%c",ch1);
			CH1--;
		}
		printf("%c",ch2);
		if(CH2>0){
			while(CH2>0){
			printf("%c",ch1);
			CH2--;
			}
			printf("%c",ch2);
		}
		printf("\n");
	}
	return 0;
}