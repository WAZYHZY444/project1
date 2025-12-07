#include <stdio.h>
int main()
{
	int n;
	int p1=0,p2=0,p3=0,p4=0;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		if(arr[i]>=0&&arr[i]<=18)p1++;
		if(arr[i]>=19&&arr[i]<=35)p2++;
		if(arr[i]>=36&&arr[i]<=60)p3++;
		if(arr[i]>=61)p4++;
	}
	double P1,P2,P3,P4;
	P1=(double)p1/n*100.0; //p1/n 中两个都是整数，会进行整数除法（结果会被截断）
	P2=(double)p2/n*100.0;
	P3=(double)p3/n*100.0;
	P4=(double)p4/n*100.0;
	printf("%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%\n",P1,P2,P3,P4); //用%%打印百分号
	return 0;
}