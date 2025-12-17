#include <stdio.h>
char* my_strcat(char* dest,const char* src)
{
	char* ret=dest;
//通过不同的指针访问同一块内存，ret指向的地址没有改变，但ret指向的内容因为dest发生了改变
	if(dest!=NULL&&src!=NULL){	
		while(*dest!='\0'){
			dest++;
		}
		while(*dest++=*src++){
			;
		}
	}
	return ret;
}
int main()
{
	char arr1[20]="hello ";
	my_strcat(arr1,"world");
	printf("%s\n",arr1);
	return 0;
}