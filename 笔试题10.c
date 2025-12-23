#include <stdio.h>
#include <stdlib.h>
char* GetMemory(void)
{
	char p[]="Hello World";  //p是局部数组，当生命周期结束后，分配给数组p的这块空间就被销毁了，还给了系统
	return p;                //能够把p所指向的地址传给str
}
void Test1()
{
	char* str=NULL;
	str=GetMemory();
	printf(str);     //能够得到p所指向的地址，但是那块空间已经不在，对str访问，访问的内容不再是Hello World
}

void Test2(void)
{
	char* str=(char*)malloc(100);
	strcpy(str,"Hello");
	free(str);            //与上面的问题一样，str的地址不变，但是free(str)已经释放了那块空间
	if(str!=NULL){
		strcpy(str,"World");  //非法访问
		printf(str);
	}
}


int main()
{
	Test1();
	Test2();
	return 0;
}

