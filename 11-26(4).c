#include <stdio.h>
#include <string.h>
int main()
{
	char arr[51];
	scanf("%s",arr);
	int num=strlen(arr);
	for(int i=0;i<num;i++){
		if(arr[i]>='a'&&arr[i]<='z'){
			arr[i]=arr[i]-32;
		}
		else if(arr[i]>='A'&&arr[i]<='Z'){
			arr[i]=arr[i]+32;
		}
	}
	
	for(int i=0;i<num/2;i++){
		//arr[i]=arr[num-1-i];  会覆盖前面的字符，是错误的！
		char temp=arr[i];
		arr[i]=arr[num-1-i];
		arr[num-1-i]=temp;
	}
	
	for(int i=0;i<num;i++){
		if(arr[i]>='X'&&arr[i]<='Z'||arr[i]>='x'&&arr[i]<='z'){
			arr[i]=arr[i]-23;
		}
		else if(arr[i]>='a'&&arr[i]<='w'||arr[i]>='A'&&arr[i]<='W'){
			arr[i]=arr[i]+3;
		}
	}
	printf("%s\n",arr);
	return 0;
}