#include <stdio.h>
#include <string.h>
int main()
{
	char arr[10];
	scanf("%s",arr);
	int len=strlen(arr);
	for(int i=0;i<len/2;i++){
		int temp=arr[len-1-i];
		arr[len-1-i]=arr[i];
		arr[i]=temp;
	}
	printf("%s\n",arr);
	return 0;
}