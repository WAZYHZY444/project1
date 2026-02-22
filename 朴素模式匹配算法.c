#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* MatchString(const char* text,const char* pattern)
{
	int n=strlen(text);
	int m=strlen(pattern);
	
	//找到母串所有的相邻字串，与模式串进行匹配。母串一共有(n-m+1)个字串，+1用来存放结束标记
	int* temp=(int*)malloc((n-m+2)*sizeof(int));
	int count=0;
	
	if(n<m){
		temp[0]=-1;
		return temp;
	}
	
	for(int i=0;i<n-m+1;i++){
		int j=0;
		while(j<m&&text[i+j]==pattern[j]){
			j++;
		}
		//模式串与字串全部一一匹配
		if(j==m){
			temp[count++]=i;  //i就是模式串首字母在母串的位置(可以将模式串在母串所有匹配位置都记录在temp中)
		}
	}
	//添加结束标记
	temp[count]=-1;
	return temp;
}
 int main()
 {
 	const char* text="abcdefghcdefgh";  //母串
 	const char* pattern="efg";    //模式串
 	int* result=MatchString(text,pattern);
 	for(int i=0;result[i]!=-1;i++){
 		printf("%d ",result[i]+1);
	}
	printf("\n");
	free(result);
	return 0;
 }