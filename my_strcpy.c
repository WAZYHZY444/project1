#include <stdio.h>
#include <assert.h>
/*
void my_strcpy(char* dest,const char* src)
{
	if(dest!=NULL&&src!=NULL){
		while(*src!='\0'){
			*dest++ = *src++;
		}
		*dest=*src; //把'\0'赋值到目标空间
	}
}
int main()
{
	char arr1[20]={0};
	char arr2[]="Hello,World";
	my_strcpy(arr1,arr2);
	printf("%s\n",arr1);
	return 0;
}
*/

char* my_strcpy(char* dest,const char* src)
{
	char* ret=dest;
	if(dest!=NULL&&src!=NULL){
		while((*dest++ = *src++))  //当*src为'\0'时，'\0'赋值给*dest，'\0'的ASCII码值为0，表达式的结果为0，为假，循环停下来
		{
			;
		}
	}
	return ret;
}
int main()
{
	char arr1[20]={0};
	char arr2[]="Hello,World";
	printf("%s\n",my_strcpy(arr1,arr2));
	return 0;
}