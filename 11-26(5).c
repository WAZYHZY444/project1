#include <stdio.h>
#include <string.h>
int main()
{
	char arr[101];
	fgets(arr,sizeof(arr),stdin);
	int num=strlen(arr);
	for(int i=0;i<num;i++){
		if(arr[i]>='a'&&arr[i]<='z'){
			arr[i]=arr[i]-32;
		}
	}
	printf("%s\n",arr);
	return 0;
}