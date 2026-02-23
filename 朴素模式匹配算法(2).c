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
		if(S.ch[i]==T.ch[j]){
			i++;
			j++;
		}else{
			i=i-j+2;  //i指针回溯
			j=1;
		}
	}
	if(j>T.length){
		return i-T.length;
	}else{     //模式串与母串完全不匹配
		return 0;
	}
}
//最坏时间复杂度：O(mn)