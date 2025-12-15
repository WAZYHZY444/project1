#include <stdio.h>
#include <stdbool.h>
bool isLeapYear(int year)
{
	return (year%4==0&&year%100!=0||year%400==0);
}
int main()
{
	int yearStart,yearEnd;
	int count=0;
	scanf("%d %d",&yearStart,&yearEnd);
	int ret=yearEnd-yearStart;
	for(int i=yearStart;i<=yearEnd;i++){
		if(isLeapYear(i)){
			count++;
		}
	}
	int arr[count];
	int j=0;
	for(int i=yearStart;i<=yearEnd;i++){
		if(isLeapYear(i)){
			arr[j]=i;
			j++;
		}
	}
	printf("%d\n",count);
	for(int i=0;i<j;i++){  //j 在循环中是自增后的值，所以有效索引是 0 到 j-1
		printf("%d ",arr[i]);
	}
	return 0;
}