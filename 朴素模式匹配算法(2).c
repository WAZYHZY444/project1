#include <stdio.h>
#include <string.h>

int Match(const char* text,const char* pattern)
{
	int len1=strlen(text);
	int len2=strlen(pattern);
	int i=0,j=0;
	while(i<len1&&j<len2){
		if(pattern[j]==text[i]){
			i++;
			j++;
		}
		else{
			i=i-j+1;   //i指针回溯
			j=0;
		}	
	}
	if(j>=len2)
		return i-len2;
	else
		return 0;
}

int main()
{
	const char* text="abcdefghcdefgh";  //母串
	const char* pattern="efg";    //模式串
	int  result=Match(text,pattern);
	printf("%d\n",result+1);
	return 0;
}

//最坏时间复杂度：O(mn)