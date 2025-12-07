#include <stdio.h>
#include <string.h>
int main()
{
	char arr[101];
	char MAX[101];
	char MIN[101];
	int max_len;
	int min_len;
	if(scanf("%100s",arr)==1){  //当成功读取到一个单词时，条件为真
		int len=strlen(arr);
		strcpy(MAX,arr);
		strcpy(MIN,arr);
		max_len=len;
		min_len=len;
		while(scanf("%100s",arr)==1){
	//scanf 的返回值规则：成功读取数据：
	//                    返回读取到的变量数量（比如 %s 返回 1）
    //                   遇到文件结束(EOF)：返回 EOF（通常是 -1）
    //                  读取失败：返回 0
//if和while循环的条件相同并不多余
//输入："Hello" + EOF
//第一个 scanf 读取 "Hello"，条件成立，进入if，while循环中的 scanf 遇到EOF，返回EOF，不进入循环，直接输出结果
			int Len=strlen(arr);
			if(Len>max_len){
				strcpy(MAX,arr);
				max_len=Len;
			}
			if(Len<min_len){
				strcpy(MIN,arr);
				min_len=Len;
			}
		}
		printf("%s\n",MAX);
		printf("%s\n",MIN);
	}
	return 0;
}