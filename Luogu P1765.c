#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char arr[201];
	int count=0;
	fgets(arr,sizeof(arr),stdin);
	int len=strlen(arr);
	for(int i=0;i<len;i++){
		if(arr[i]!=' '){
			if(arr[i]>='a'&&arr[i]<='o'){
				count+=(arr[i]-'a')%3+1;
			}
			else if(arr[i]>='p'&&arr[i]<='s'){
				count+=(arr[i]-'p')%4+1;
			}
			else if(arr[i]>='t'&&arr[i]<='v'){
				count+=(arr[i]-'t')%3+1;
			}
			else if(arr[i]>='w'&&arr[i]<='z'){
				count+=(arr[i]-'w')%4+1;
			}
		}
		if(arr[i]==' '){
			count+=1;
		}
	}
	printf("%d\n",count);
	return 0;
}