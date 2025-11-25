#include <stdio.h>
#include <string.h>
int main()
{
	char arr[256];
	scanf("%s",arr);
	int num=strlen(arr);
	for(int i=0;i<num;i++){
		if(arr[i]=='A'){
			arr[i]='T';
		}
		else if(arr[i]=='T'){
			arr[i]='A';
		}
		else if(arr[i]=='G'){
			arr[i]='C';
		}
		else if(arr[i]=='C'){
			arr[i]='G';
		}
	}
	printf("%s\n",arr);
	return 0;
}