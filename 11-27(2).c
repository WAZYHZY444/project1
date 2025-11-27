#include <stdio.h>
#include <string.h>
int main()
{
	double n;
	int count=0;
	scanf("%lf",&n);
	char arr1[501];
	char arr2[501];
	scanf("%s %s",arr1,arr2);
	int num=strlen(arr1);
	for(int i=0;i<num;i++){
		if(arr1[i]==arr2[i]){
			count++;
		}
	}
	double ret=1.0*count/num;
	if(ret>=n){
		printf("yes\n");
	}else{
		printf("no\n");
	}
	return 0;
}