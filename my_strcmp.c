#include <stdio.h>
int my_strcmp(const char *str1, const char *str2)
{
	if(str1!=NULL&&str2!=NULL){
		while(*str1==*str2){
			if(*str1=='\0'){
				return 0;  //两个字符串相等
			}
			str1++;
			str2++;
		}
		return (*str1-*str2);
	}
}
int main()
{
	char arr1[]="abq";
	char arr2[]="abcd";
	int ret=my_strcmp(arr1,arr2);
	if(ret<0)
		printf("<\n");
	else if(ret>0)
		printf(">\n");
	else
		printf("==\n");
	return 0;
}