#include <stdio.h>
#include <string.h>
/*
int main()
{
//strstr函数如果字串存在，返回字串在母串所在的地址；如果字串不存在，则返回空指针
	char arr1[]="hello world!";
	char arr2[]="world";
	char* ret=strstr(arr1,arr2);
	if(ret==NULL){
		printf("字串不存在\n");
	}else{
		printf("%s\n",ret);
	}
	return 0;
}
*/

char* my_strstr(const char* str1,const char* str2)
{
	if(str1!=NULL&&str2!=NULL){
		const char* s1=str1;
		const char* s2=str2;
		const char* p=str1;
		while(*p){ //*p!='\0'
			s1=p;
			s2=str2;
			while(*s1!='\0'&&*s2!='\0'&&*s1==*s2){
				s1++;
				s2++;
			}
			if(*s2=='\0'){
				return (char*)p;
			}
			p++;
		}
		return NULL;
	}
}
int main()
{
	char arr1[]="hello world!";
	char arr2[]="world";
	char* ret=strstr(arr1,arr2);
	if(ret==NULL){
		printf("字串不存在\n");
	}else{
		printf("%s\n",ret);
	}
	return 0;
}