#include <stdio.h>
#include <string.h>
int main()
{
	char s[301],s1[11],s2[11];
	int n1=-1,n2=-1;
	scanf("%300[^,],%10[^,],%10s",s,s1,s2);
	int num0=strlen(s);
	int num1=strlen(s1);
	int num2=strlen(s2);
	for(int i=0;i<=num0-num1;i++){  //num0-num1的目的是为了防止s[i+j]越界访问
		int mark=1;
//只有找到s1的第一个字符，才会进入内层循环进行j++操作，才有机会做完所有的内层循环，就不会break
//mark就不会等于0；此时mark标记的是s1的首个字符的位置
		for(int j=0;j<num1;j++){
			if(s[i+j]!=s1[j]){
				mark=0;
				break;
			}
		}
		if(mark){
			n1=i+num1;
			break;
		}
	}
	for(int i=num0-num2;i>=0;i--){  //如果s2刚好在s的最后，此处的i便是从s2的首个字符开始时向前检查，正好进入内层循环做j++,不用担心s2在s最后而检查不到
		int mark=1;
		for(int k=0;k<num2;k++){
			if(s[i+k]!=s2[k]){
				mark=0;
				break;
			}
		}
		if(mark){
			n2=i;
			break;
		}
	}
	if(n1==-1||n2==-1||n2<=n1){
		printf("-1\n");
	}else{
		printf("%d\n",n2-n1);
	}
	return 0;
}