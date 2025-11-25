#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char s[81];
	fgets(s,sizeof(s),stdin);
	int num=strlen(s);
	for(int i=0;i<num;i++){
		if(s[i]>='a'&&s[i]<='z'){
		s[i]=s[i]-32; //小->大
		}
		else if(s[i]>='A'&&s[i]<='Z'){
		s[i]=s[i]+32; //大->小
		}
	}
	printf("%s\n",s);
	return 0;
}