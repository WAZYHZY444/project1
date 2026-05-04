#include <stdio.h>
#include <string.h>

int Add(int x,int y){
	return x+y;
}
int Sub(int x,int y){
	return x-y;
}
int Mul(int x,int y){
	return x*y;
}

//函数指针数组
int (*arr[4])(int,int)={0,Add,Sub,Mul};

char option[4]={' ','+','-','*'};

int main()
{
	/*因为输出每一行元素个数不相同，把每一行的输出当作一个字符串，所以需要解决的问题：
		1.去除换行
		2.数字字符要转换成数字
	*/
	
	int n;
	scanf("%d",&n);
	getchar();
	
	int x_value[100],y_value[100],marks[100];
	int p_mark=0;   //为了记录上一行的运算符号
	
	for(int i=0;i<n;i++){
		char ch[100];
		scanf(" %[^\n]",ch);  //读取一整行字符串，直到按下回车为止，且保留字符串中的空格.开头的空格是跳过所有空白字符
		
		int mark=p_mark;
		int x=0, y=0;
		
		//如果第一个字符是a~b，就更新mark;如果不是a~b，就不更新mark，使用上一行的mark
		if(ch[0]>='a'&&ch[0]<='c'){
			mark=ch[0]-'a'+1;
			
			int j=2;
			while(ch[j]==' ') j++;
			while(ch[j]>='0'&&ch[j]<='9'){
				x=x*10+(ch[j]-'0');
				j++;
			}
			while(ch[j]==' ') j++;   //跳过第一个数字与第二个数字之间的空格
			while(ch[j]>='0'&&ch[j]<='9'){
				y=y*10+(ch[j]-'0');
				j++;
			}
		}else{  //第一个字符不是a~b
			int j=0;
			while(ch[j]>='0'&&ch[j]<='9'){
				x=x*10+(ch[j]-'0');
				j++;
			}
			while(ch[j]==' ') j++;   //跳过第一个数字与第二个数字之间的空格
			while(ch[j]>='0'&&ch[j]<='9'){
				y=y*10+(ch[j]-'0');
				j++;
			}
		}
		
		//存储信息
		x_value[i]=x;
		y_value[i]=y;
		marks[i]=mark;
		p_mark=mark;   //保存本行的mark
	}
	
	//统一输出
	for(int i=0;i<n;i++){
		int ret=arr[marks[i]](x_value[i],y_value[i]);
		char temp[100];
		//把x_value[i],option[mark[i]],y_value[i],ret数据转化成字符串放到temp中,并且以%d%c%d=%d的形式存在
		sprintf(temp,"%d%c%d=%d",x_value[i],option[marks[i]],y_value[i],ret);
		
		printf("%s\n",temp);
		printf("%d\n",strlen(temp));
	}
	return 0;
}