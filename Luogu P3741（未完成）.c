#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int n;
	int count=0;
	scanf("%d",&n);
	char arr[n+1];
	scanf("%s",arr);
	int len=strlen(arr);
	for(int i=0;i<len;i++){
		if(arr[i]=='V'&&arr[i+1]=='K'){
			count++;
		}
	}
	for(int i=0;i<len;i++){
		if(arr[i]=='V'&&arr[i+1]=='V'){
			count++;
			break;
		}
		else if(arr[i]=='K'&&arr[i+1]=='K'&&arr[i-1]!='V'){
			count++;
			break;                                        
		}
	}
	printf("%d\n",count);
	return 0;
}