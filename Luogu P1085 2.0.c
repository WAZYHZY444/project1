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