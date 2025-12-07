#include<stdio.h>
int main()
{
	int s;
	int v;
	int t2=0;
	scanf("%d %d",&s,&v);
	int t1=s/v;
	int a=s%v;
	if(a=0){
		t2=t1+10;
	}else{
		t2=t1+11;
	}
	if(t2>=60){
		int n=t2/60;
		int t=t2%60;
		
		printf("0%d:%2d",7-n,60-t);
	}else{
		printf("07:%2d",60-t2);
	}
	return 0;
}