#include <stdio.h>
#define MAXLEN 255

typedef struct
{
	char ch[MAXLEN];
	int length;
}String;

int Match(String S,String T)
{
	int i=1,j=1;    //跳过下标为0
	while(i<=S.length&&j<=T.length){
		if(j==0||S.ch[i]==T.ch[j]){
			i++;
			j++;
		}else{
			j=next[j];  //i指针不用回溯
		}
	}
	if(j>T.length){
		return i-T.length;
	}else{     //模式串与母串完全不匹配
		return 0;
	}
}
//最坏时间复杂度：O(m+n)
//next数组时间复杂度O(m),模式匹配过程最坏时间复杂度O(n)