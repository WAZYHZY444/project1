/*
#include <stdio.h>
#include <string.h>
int main()
{
//求字符串长度
	char s[30];
	gets(s);
	printf("%d\n",strlen(s));
	return 0;
}
*/
	
#include <stdio.h>
#include <string.h>	
//字符串复制
//strcpy不安全，不检查边界
//strcpy在拷贝字符串时，会把源字符串中的\0也拷贝过去
//dest:指向目标字符数组的指针，用于存放复制后的字符串。这个数组必须足够大
//src:指向要复制的源字符串的指针
/*int main()
{
	char src[20],dest[100]; 
	gets(src);
	strcpy(dest,src);    //dest和src的位置不能反 strcpy（目标空间，源数据）  dev c++不支持C11
	printf("%s\n",dest);
	return 0;
}
*/

/*
int main()
{
//strncpy相对安全，但需手动添加 \0
	char src[20],dest[100]; 
	gets(src);
	strncpy(dest,src,sizeof(dest)-1);  //sizeof(dest) - 1是限制复制的长度，避免源字符串的长度超过目标空间
	dest[sizeof(dest)-1]='\0';
	printf("%s\n",dest);
	return 0;
}
*/

/*
//字符串连接
int main()
{
	char src[20],dest[20];
	gets(src);
	gets(dest);
	strcat(src,dest);  //要输出的参数写在参数列表第一个
	printf("%s",src);   
}
*/

/*
int main()
{
	char s[20],t[20];
	gets(s);
	gets(t);
	strncat(s,t,sizeof(s)-1);
	s[sizeof(s)-1]='\0';
	printf("%s",s);
	return 0;
}
*/

/*
int main()
{
//字符串比较
	char s[20],t[20];
	gets(s);
	gets(t);
	if(strcmp(s,t)==0){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
*/

/*
int main()
{
//字符串大小写转换
	char s[]="I like zhangyuan";
	printf("%s\n",s);
	strlwr(s);
	printf("%s\n",s);
	strupr(s);
	printf("%s\n",s);
	return 0;
}
*/

//char tolower(char c);    // 将大写字母转换为小写
//char toupper(char c);    // 将小写字母转换为大写

/*
int main()
{
	const char* sep="@.";  //分隔符
	const char email[]="zhangpengwei@bitzaijiuye.com.net"; //被分割的字符串
	char cp[40]={0};
	strcpy(cp,email);
	char* ret=NULL;
	for(ret=strtok(cp,sep);ret!=NULL;ret=strtok(NULL,sep)){
		printf("%s\n",ret);
	}

//	char* ret=strtok(cp,sep); //将email里的@改为'\0',返回'z'的地址
//	printf("%s\n",ret);
//	ret=strtok(NULL,sep); //将email里的.改为'\0',返回'b'的地址
//	printf("%s\n",ret);
//	ret=strtok(NULL,sep);  //返回'c'的地址
//	printf("%s\n",ret);

	return 0;
}
*/

/*
#include <errno.h>
int main()
{
//	printf("%s\n",strerror(0));
//	printf("%s\n",strerror(1));
//	printf("%s\n",strerror(2));
//	printf("%s\n",strerror(3));
//	printf("%s\n",strerror(4));
//	printf("%s\n",strerror(5));

//errno 是C语言设置的一个全局的错误码存放的变量

	FILE* pf=fopen("test.txt","r");
	if(pf==NULL){
		printf("%s\n",strerror(errno));
		return 1;  //当main函数的返回值为非0时，表示异常退出程序
	}else{
		
	}
	return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[]="hello world";
	//memset(arr,'x',5);
	memset(arr+6,'x',5);  //设置的起始位置，要设置成的内容，要被设置的大小（单位是字节）
	printf("%s\n",arr);
	return 0;
}
*/

//用strcspn来处理fgets带来的换行符
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[20];
	fgets(arr,sizeof(arr),stdin);
	printf("%d\n",strlen(arr));
	arr[strcspn(arr,"\n")]='\0';   //注意：strcspn的第二个参数是字符串不是字符，所以需要用双引号
	printf("%d\n",strlen(arr));
	return 0;
}











