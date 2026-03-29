#include <iostream>  //有些编译器的<iostream>可能会间接包含<algorithm>，但这不是标准保证的
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
char s1[505],s2[505];      //全局变量
int a[505],b[505],c[505];  //全局数组会自动初始化为0，而c[i] += a[i] + b[i]这行代码依赖初始值为0
int main()
{
	int la,lb,lc;
	scanf("%s",s1);
	scanf("%s",s2);
	
	la=strlen(s1);
	lb=strlen(s2);
	
	for(int i=0;i<la;i++){
		a[la-i]=s1[i]-'0';
	}
	for(int i=0;i<lb;i++){
		b[lb-i]=s2[i]-'0';
	}
	
	lc=max(la,lb)+1;    //有可能最高位还要进位，所以要把lc的长度多留一位
	for(int i=1;i<=lc;i++){
		c[i]+=a[i]+b[i];  //累加的目的是有可能前一位有进位值，需要的把本位a[i]+b[i]的值和进位的值累加起来
		c[i+1]=c[i]/10;
		c[i]=c[i]%10;
	}
	if(c[lc]==0&&lc>0)lc--;  //删除前导0， lc>0是为防止出现0+0情况把结果0也删掉
	for(int i=lc;i>0;i--){
		printf("%d",c[i]);
	}
	return 0;
}
