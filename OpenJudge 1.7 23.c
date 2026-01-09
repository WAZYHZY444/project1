#include <stdio.h>
#include <string.h>
int main()
{
	char arr[201];
	char brr[201]={'\0'};
	fgets(arr,sizeof(arr),stdin);
	arr[strcspn(arr,"\n")]='\0';
	int len=strlen(arr);
	int j=0;
	for(int i=0;i<len;i++){
		if(arr[i]!=' '){
			brr[j]=arr[i];
		}
		else if(arr[i]==' '){
			brr[j]=arr[i];
			while(i+1<len&&arr[i+1]==' '){    //学习：如何连续跳过
				i++;
			}
		}
		j++;
	}
	brr[j]='\0';
	printf("%s\n",brr);
	return 0;
}