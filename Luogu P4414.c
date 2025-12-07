#include <stdio.h>
#include <string.h>
int main()
{
	int arr[3];
	int B=0;
	for(int i=0;i<3;i++){
		scanf("%d",&arr[i]);
	}
	int C=arr[0];
	int A=arr[0];
	for(int j=0;j<3;j++){
		if(arr[j]>C){
			C=arr[j];
		}
		if(arr[j]<A){
			A=arr[j];
		}
	}
	B=arr[0]+arr[1]+arr[2]-A-C;
	char c[10];
	scanf("%s",c);
	if(strcmp(c,"ABC")==0){
		printf("%d %d %d\n",A,B,C);
	}else if(strcmp(c,"ACB")==0){
		printf("%d %d %d\n",A,C,B);
	}else if(strcmp(c,"BAC")==0){
		printf("%d %d %d\n",B,A,C);
	}else if(strcmp(c,"BCA")==0){
		printf("%d %d %d\n",B,C,A);
	}else if(strcmp(c,"CAB")==0){
		printf("%d %d %d\n",C,A,B);
	}else if(strcmp(c,"CBA")==0){
		printf("%d %d %d\n",C,B,A);
	}
	return 0;
}