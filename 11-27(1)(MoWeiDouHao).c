#include <stdio.h>
#include <string.h>
int main()
//注意这里的不输出末尾逗号的小技巧
{
	char arr[1000];
	int mark=1;
	while(scanf("%s",arr)==1){
		int num=strlen(arr);
		if(!mark)printf(",");
		printf("%d",num);
		mark=0;
	}
	return 0;
}