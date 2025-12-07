#include<stdio.h>
int main()
{
	int s;
	int v;
	//int t2=0;
	scanf("%d %d",&s,&v);
	/*int t1=s/v;
    int a=s%v;    //考虑s/v是否能除尽  用向上取整的方法来简化过程，避免使用if-else语句
	if(a=0){
		t2=t1+10;
	}else{
		t2=t1+11;
	}
    */
    int t2=(s+v-1)/v+10;  //向上取整
	int T=8*60;
	int t0=T-t2;
	int H=t0/60;
	int M=t0%60;
	printf("%02d:%02d",H,M);
	
	/*if(t2>=60){
		int n=t2/60;
		int t=t2%60;
		
		printf("0%d:%2d",7-n,60-t);
	}else{
		printf("07:%2d",60-t2);
	}
    */
	return 0;
}