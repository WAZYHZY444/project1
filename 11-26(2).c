#include <stdio.h>
#include <string.h>
int main()
{
	char arr[201];
	fgets(arr,sizeof(arr),stdin);
	int num=strlen(arr);
	for(int i=0;i<num;i++){
		if(arr[i]>='A'&&arr[i]<='Z'){
			if(arr[i]>='A'&&arr[i]<='E'){
			arr[i]=arr[i]+21;
			}
		else if(arr[i]>='F'&&arr[i]<='Z'){
			arr[i]=arr[i]-5;
			}
		}
	}
	printf("%s\n",arr);
	return 0;
}