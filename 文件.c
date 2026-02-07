#include <stdio.h>
#include <string.h>
#include <errno.h>
/*
int main()
{
	//打开文件
	FILE* pf=fopen("test.txt","r");
	if(pf==NULL){
		printf("%s\n",strerror(errno));
		return 1;
	}
	//关闭文件
	fclose(pf);
	pf=NULL;
	return 0;
}
*/

/*
//写单个字符
int main()
{
	FILE* pf=fopen("test.txt","w");
	if(pf==NULL){
		printf("%s\n",strerror(errno));
		return 1;
	}
	//写文件
	char i=0;
	for(i='a';i<'z';i++){
		fputc(i,pf);
	}
	//关闭文件
	fclose(pf);
	pf=NULL;
	return 0;
}
*/


int main()
{
	FILE* pf=fopen("test.txt","r");
	if(pf==NULL){
		printf("%s\n",strerror(errno));
		return 1;
	}
	//读文件
//	int ch=fgetc(pf);
//	printf("%c\n",ch);
//	ch=fgetc(pf);
//	printf("%c\n",ch);
//	ch=fgetc(pf);
//	printf("%c\n",ch);
	int ch=0;
	while((ch=fgetc(pf))!=EOF){
		printf("%c ",ch);
	}
	//关闭文件
	fclose(pf);
	pf=NULL;
	return 0;
}


/*
//写一行数据
int main()
{
	FILE* pf=fopen("test.txt","w");
	if(pf==NULL){
		//printf("%s\n",strerror(errno));
		perror("fopen");   //打印错误信息，可以在perror里加入自定义字符串，打印的时候会在自定义字符串后面加一个冒号，在打印错误类型
		return 1;
	}
	//写一行数据
	fputs("Hello World\n",pf);
	
	//关闭文件
	fclose(pf);
	pf=NULL;
	return 0;
}
*/

/*
//读一行数据
int main()
{
	FILE* pf=fopen("test.txt","r");
	if(pf==NULL){
		printf("%s\n",strerror(errno));
		return 1;
	}
	//读一行数据
	char arr[20];
	fgets(arr,5,pf);  //读的字符个数里面包含一个'\0'
	printf("%s\n",arr);

	//关闭文件
	fclose(pf);
	pf=NULL;
	return 0;
}
*/

/*
struct S
{
	char arr[10];
	int age;
	float score;
};
int main()
{
	struct S s={"zhangshan",23,50.5f};
	FILE* pf=fopen("test.txt","w");
	if(pf==NULL){
		perror("fopen");
		return 1;
	}
	fprintf(pf,"%s %d %f",s.arr,s.age,s.score);

	//关闭文件
	fclose(pf);
	pf=NULL;
	return 0;
}
*/

/*
struct S
{
	char arr[10];
	int age;
	float score;
};
int main()
{
	struct S s={0};
	FILE* pf=fopen("test.txt","r");
	if(pf==NULL){
		perror("fopen");
		return 1;
	}
	
	fscanf(pf,"%s %d %f",s.arr,&(s.age),&(s.score));
	//printf("%s %d %f\n",s.arr,s.age,s.score);
	fprintf(stdout,"%s %d %f\n",s.arr,s.age,s.score);

	//关闭文件
	fclose(pf);
	pf=NULL;
	return 0;
}
*/

/*
struct S
{
	char arr[10];
	int age;
	float score;
};
int main()
{
	struct S s={"zhangshan",23,50.5f};
	//以二进制的形式写到文件中
	FILE* pf=fopen("test.txt","wb");
	if(pf==NULL){
		perror("fopen");
		return 1;
	}
	//以二进制的方式写
	fwrite(&s,sizeof(struct S),1,pf);

	//关闭文件
	fclose(pf);
	pf=NULL;
	return 0;
}
*/

/*
struct S
{
	char arr[10];
	int age;
	float score;
};
int main()
{
	struct S s={0};
	FILE* pf=fopen("test.txt","rb");
	if(pf==NULL){
		perror("fopen");
		return 1;
	}
	//以二进制的方式读
	fread(&s,sizeof(struct S),1,pf);
	printf("%s %d %f\n",s.arr,s.age,s.score);
	
	//关闭文件
	fclose(pf);
	pf=NULL;
	return 0;
}
*/

/*
//文件随机读写
//fseek根据文件的位置和偏移量来定位文件指针
//ftell返回文件指针相对于起始位置的偏移量
//rewind让指针的位置回到文件的起始位置
int main()
{
	FILE* pf=fopen("test.txt","r");
	if(pf==NULL){
		printf("%s\n",strerror(errno));
		return 1;
	}
	//读文件
	//定位文件指针
	fseek(pf,2,SEEK_SET);
	int ch=fgetc(pf);
	printf("%c\n",ch);
	printf("%d\n",ftell(pf));
	
	fseek(pf,-1,SEEK_END);
	ch=fgetc(pf);
	printf("%c\n",ch);
	printf("%d\n",ftell(pf));
	
	rewind(pf);
	
	//关闭文件
	fclose(pf);
	pf=NULL;
	return 0;
}
*/

