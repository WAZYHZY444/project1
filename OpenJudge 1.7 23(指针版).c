#include <stdio.h>
#include <string.h>
char* test(char* str)
{
	int len=strlen(str);
	char* src=str;
	char* p=str;
	int mark=0;
	while(*str!='\0'){
		if(*str==' '){
			if(!mark){
				*p=*str;
				mark=1;  //确保遇到连续空格时，只允许赋值给p一个空格
				p++;
			}
			str++;   //当遇到第一个空格后出现连续空格，及连续执行str++，直到再次遇到非空格，进入else判断
		}else{       //当再次遇到非空格，进入else判断
			*p=*str;
			str++;
			p++;
			mark=0;  //这里把mark赋值为1，是让它有机会进入if(!mark)判断，因为遇到空格，需要赋值一个空格，不能跳过所有的空格，所以需要进入if(!mark)判断，去复制一个空格
		}
	}
	*p='\0';
	return src;
}
int main()
{
	char arr[201];
	fgets(arr,sizeof(arr),stdin);
	arr[strcspn(arr,"\n")]='\0';
	
	char* r=test(arr);
	printf("%s\n",r);
	return 0;
}