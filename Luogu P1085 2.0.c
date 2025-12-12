#include <stdio.h>
int main()
{
	int hour[7]={0};
	int a,b;
	for(int i=0;i<7;i++){
		scanf("%d %d",&a,&b);
		hour[i]=a+b;
	}
	int max=hour[0];
	int day=1;
	for(int i=0;i<7;i++){
		if(hour[i]>max){
			max=hour[i];
			day=i+1;
		}
	}
	if(max<=8){
		printf("0\n");
	}else{
		printf("%d\n",day);
	}
	return 0;
}

/*
#include <stdio.h>
int main()
{
	int arr[7][2];
	for(int i=0;i<7;i++){
		for(int j=0;j<2;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int brr[7];
	for(int i=0;i<7;i++){
		brr[i]=arr[i][0]+arr[i][1];
	}
	int max=brr[0];
	for(int i=0;i<7;i++){
		if(brr[i]>max){
			max=brr[i];
		}
	}
	if(max<=8){
		printf("0\n");
	}else{
		for(int i=0;i<7;i++){
			if(brr[i]==max){
				printf("%d\n",i+1);
				break;
			}
		}
	}
	return 0;
}
*/