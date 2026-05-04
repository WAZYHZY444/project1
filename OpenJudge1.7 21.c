#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char str[101];
	char s1[101];
	char s2[101];
	int tag=-1;
	gets(str);
	gets(s1);
	gets(s2);
	int lt=strlen(str);
	int l1=strlen(s1);
	for(int i=0;i<=lt-l1;i++){
		int j=0;
		for(j=0;j<l1;j++){
			if(str[i+j]!=s1[j]){
				break;
			}
		}
		//不要遗漏i+l1==lt的判断，因为有可能替换单词是最后一个的单词，后面没有空格
		if(j==l1&&(i+l1==lt||str[i+l1]==' ')){
			tag=i;
			break;
		}
	}
	char front[101];
	//去掉替换单词及其之前的字符串，还剩下的长度是(lt-tag-l1)
	memcpy(front,str+tag+l1,(lt-tag-l1)*sizeof(char));
	//记得要手动添加结束字符
	front[lt-tag-l1]='\0';
	char total[201]={0};  //需要初始避免出现乱码
	if(tag==0){
		strcpy(total,s2);
		strcat(total,front);
		printf("%s",total);
	}else{
		//复制替换单词之前的内容
		int k=0;
		for(int i=0;i<tag;i++){
			total[k]=str[i];
			k++;
		}
		total[k]='\0';
		strcat(total,s2);
		strcat(total,front);
		printf("%s",total);
	}
	return 0;
}