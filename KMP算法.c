#include <stdio.h>
#include <string.h>
void getNext(int next[],char* pattern)
{
	int l=strlen(pattern);
	int i=1,j=0;
	next[0]=0;
	while(i<l){
		if(pattern[i]==pattern[j]){
			j++;
			next[i]=j;
			i++;
		}
		else{
			if(j!=0)
				j=next[j-1];
			else
				next[i++]=0;
		}	
	}
}

int KMP_Match(char* text,char* pattern)
{
	int len1=strlen(text);
	int len2=strlen(pattern);
	int next[len2];
	getNext(next,pattern);
	
	if(len2==0) return 0;
	
	int i=0,j=0;
	while(i<len1){
		if(text[i]==pattern[j]){
			i++;
			j++;
		}
		if(j==len2){
			return i-len2;
		}
		else if(i<len1&&text[i]!=pattern[j]){
			if(j!=0)
				j=next[j-1];
			else
				i++;
		}	
	}
	return -1;  //匹配失败
}

int main()
{
	char* text="abbcabcacbcaa";
	char* pattern="abca";
	int result=KMP_Match(text,pattern);
	printf("%d\n",result+1);
}