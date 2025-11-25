#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char arr[100000];
	scanf("%s",arr);
	int num=strlen(arr);

	for(int i=0;i<num;i++){
	int found=1;
		for(int j=0;j<num;j++){
			if(i!=j&&arr[i]==arr[j]){
				found=0;
				break;
			}
		}
		if(found){
		printf("%c\n",arr[i]);
		return 0;
		}
	}
	printf("no\n");
	return 0;
}