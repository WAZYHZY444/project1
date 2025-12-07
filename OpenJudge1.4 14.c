#include <stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	char c;
	scanf(" %c",&c);    //第一个scanf后留下的换行符会被第二个scanf读取。在读取字符c之前，在格式字符串中加入空格以跳过空白字符
	int money;
	if(a<=1000){
		money=8;
	}else{
		money=8+4*((a-1000+500-1)/500);
	}
	if(c=='y'){
		printf("%d\n",money+5);
	}else if(c=='n'){
		printf("%d\n",money);
	}
	return 0;
}