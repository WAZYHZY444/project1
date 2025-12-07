#include <stdio.h>
int main()
{
	long long arr[3];
	for(int i=0;i<3;i++){
		scanf("%lld",&arr[i]);
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2-i;j++){
			if(arr[j]>arr[j+1]){
				int change=0;
				change=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=change;
			}
		}
	}
	long long max,min,mid;
	max=arr[2];     //注意max,min,mid的下标
	min=arr[0];
	mid=arr[1];
	//printf("max=%d min=%d mid=%d\n",max,min,mid);
	if((min+mid)<=max){     //在C语言的if-else if-else结构中，一旦某个条件为真，执行对应的代码块后，整个结构就会结束，后面的所有else if和else都不会再被判断或执行。执行流程
		printf("Not triangle\n");       //可以用多个if语句来做多次判断
		return 0;                     //若不符合三角形的条件，直接返回，结束下面的判断
	}
	if(max*max==min*min+mid*mid){
		printf("Right triangle\n");
	}
	if(max*max<min*min+mid*mid){
		printf("Acute triangle\n");
	}
	if(max*max>min*min+mid*mid){
		printf("Obtuse triangle\n");
	}
	if(max==min||max==mid||min==mid){
		printf("Isosceles triangle\n");
	}
	if(max==min&&min==mid){
		printf("Equilateral triangle\n");
	}
	return 0;
}