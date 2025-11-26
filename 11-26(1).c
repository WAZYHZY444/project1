#include <stdio.h>
#include <string.h>
int main()
{
	char arr[81];
	fgets(arr,sizeof(arr),stdin);
	int num=strlen(arr);
	for(int i=0;i<num;i++){
		if(arr[i]>='a'&&arr[i]<='z'||arr[i]>='A'&&arr[i]<='Z'){
			if(arr[i]=='z'||arr[i]=='Z'){
			arr[i]=arr[i]-25;
			}else{
				arr[i]=arr[i]+1;
			}
		}	
	}
	printf("%s\n",arr);
	return 0;
}