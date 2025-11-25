#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char arr[31];
	scanf("%s",arr);
	char arr1,arr2;
	scanf(" %c %c",&arr1,&arr2);
	int num=strlen(arr);
	for(int i=0;i<num;i++){
		if(arr[i]==arr1){
			arr[i]=arr2;
		}
	}
	printf("%s\n",arr);
	return 0;
}