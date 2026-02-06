#include <string.h>
#include <stdio.h>
char s1[505],s2[505];      //全局变量
int a[505],b[505],c[505];  //全局数组会自动初始化为0，而c[i] += a[i] + b[i]这行代码依赖初始值为0
/*
int main()
{
	int la,lb,lc;
	scanf("%s",s1);
	scanf("%s",s2);
	
	la=strlen(s1);
	lb=strlen(s2);
//没有使用索引0
	for(int i=0;i<la;i++){
		a[la-i]=s1[i]-'0';   //将字符数字转换为整数，并倒序存储
	}
	for(int i=0;i<lb;i++){
		b[lb-i]=s2[i]-'0';
	}
	
	lc=(la>lb?la:lb)+1;    //有可能最高位还要进位，所以要把lc的长度多留一位
	for(int i=1;i<=lc;i++){
		c[i]+=a[i]+b[i];  //累加的目的是有可能前一位有进位值，需要的把本位a[i]+b[i]的值和进位的值累加起来
		c[i+1]=c[i]/10;
		c[i]=c[i]%10;
	}
	if(c[lc]==0&&lc>0)lc--;  //删除前导0，最开始给lc多留了一位，计算结果最高位可能并没有向前进位，所以要删去那个0  lc>0是为防止出现0+0情况把结果0也删掉
	for(int i=lc;i>0;i--){
		printf("%d",c[i]);
	}
	return 0;
}
*/

int main()
{
	int la,lb,lc;
	scanf("%s",s1);
	scanf("%s",s2);
	
	la=strlen(s1);
	lb=strlen(s2);
//使用了索引0
	for(int i=0;i<la;i++){
		a[i]=s1[la-1-i]-'0';   //将字符数字转换为整数，并倒序存储
	}
	for(int i=0;i<lb;i++){
		b[i]=s2[lb-1-i]-'0';
	}
	
	lc=(la>lb?la:lb);    
	for(int i=0;i<lc;i++){
		c[i]+=a[i]+b[i];  //累加的目的是有可能前一位有进位值，需要的把本位a[i]+b[i]的值和进位的值累加起来
		c[i+1]=c[i]/10;
		c[i]=c[i]%10;
	}
	if(c[lc]>0){     //c[lc]>0说明进位了
		lc++;
	}
	if(lc==0){       //0+0的情况
		printf("0\n");
	}else{
		for(int i=lc-1;i>=0;i--){
			printf("%d",c[i]);
		}
	}
	return 0;
}