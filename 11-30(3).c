#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char arr[100];
	int len=0;
	//fgets(arr,sizeof(arr),stdin);
	scanf("%[^\n]",arr);
	for(int i=0;arr[i]!='\0';i++){
		if(arr[i]!=' '){
			len++;
		}
	}
	printf("%d\n",len);
	return 0;
}