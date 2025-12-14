#include <stdio.h>
#include <string.h>
int main()
{
	int k;
	int count=1;
	scanf("%d",&k);
	char arr[1001];
	char brr='\0';
	scanf(" %s",arr);
	int len=strlen(arr);
	for(int i=0;i<len;i++){
		if(i+1<len&&arr[i]==arr[i+1]){
			count++;
		}else{
			count=1;
		}
		if(count==k){
			brr=arr[i];
			break;
		}
	}
	if(brr!='\0'){
		printf("%c\n",brr);
	}else{
		printf("No\n");
	}
	return 0;
}