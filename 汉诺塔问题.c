#include <stdio.h>
void Move(char pos1,char pos2)
{
	printf("%c->%c  ",pos1,pos2);
}
//n代表盘子个数，pos1代表起始位置，pos2代表中转位置，pos3代表目的位置
void Hannuota(int n,char pos1,char pos2,char pos3)
{
	if(n==1){
		Move(pos1,pos3);
	}else{
		Hannuota(n-1,pos1,pos3,pos2);  //从pos1通过pos3移动到pos2
		Move(pos1,pos3);
		Hannuota(n-1,pos2,pos1,pos3);  //从pos2用过pos1移动到pos3
	}
}
int main()
{
	Hannuota(1,'A','B','C');
	printf("\n");
	Hannuota(2,'A','B','C');
	printf("\n");
	Hannuota(3,'A','B','C');
	printf("\n");
	return 0;
}