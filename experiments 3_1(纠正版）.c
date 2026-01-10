//在目标对象中删除子对象问题：
//1.需要创建一个新的空间，将排除了子对象的目标对象复制在这个新的空间
//2.当在目标对象遇到子对象的时候，需要来连续跳过，条件判断，符合条件，索引或指针连续++即可
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* test(char* dest,char* src)  
{
	int len_1=strlen(dest);
	int len_2=strlen(src);
	
	//创建一个新的空间
	char* temp=(char*)malloc((len_1+1)*sizeof(char));
	if(temp==NULL){
		return NULL;
	}
	//创建指针p，p与temp指向同一块空间，p负责移动赋值，temp负责保存新创建的空间的首地址，方便后面返回
	char *p=temp;
	
	while(*dest!='\0'){
		if(strncmp(dest,src,len_2)==0){
			dest+=len_2;
		}else{
			*p=*dest;
			*dest++;
			*p++;
		}
	}
	//记得最后要添加结束字符
	*p='\0';
	return temp;
}
int main()
{
	char arr1[20];  //母串
	char arr2[20];  //子串
	scanf("%s %s",arr1,arr2);
	char* result=test(arr1,arr2);
	printf("%s\n",result);
	
	free(result);
//（重点）注意：函数里的那个指针变量已经销毁了，所以free的时候就不能写函数里的返回的那个变量名，应该写main函数里接受返回的那个指针变量名
//还有，不要想着在函数里面释放内存，如果写在return之前，那返回的是野指针；如果写在return之后，return后面代码根本不会执行，释放空间无效（只针对于这一道题）
	return 0;
}