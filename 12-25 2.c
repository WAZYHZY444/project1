#include <stdio.h>
#include <string.h>
char* test(char* str2,char* str1,int m)
{
	int len=strlen(str1);
	strncpy(str2,str1+(m-1),len-(m-1));
	return str1;
}
int main()
{
	char arr1[81];
	char arr2[81]={'0'};
	scanf("%s",arr1);
	int m;
	scanf("%d",&m);
	test(arr2,arr1,m);
	printf("%s\n",arr2);
	return 0;
}