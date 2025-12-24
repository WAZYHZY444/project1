#include <stdio.h>
/*
int main() 
{
    char buffer[100];
    
    // 整数转字符串
    int num_int = 456;
    sprintf(buffer, "%d", num_int);
    printf("整数%d → 字符串'%s'\n", num_int, buffer);
    
    // 浮点数转字符串
    float num_float = 2.718;
    sprintf(buffer, "%.3f", num_float);
    printf("浮点数%.3f → 字符串'%s'\n", num_float, buffer);
    
    // 十进制转十六进制字符串
    int decimal = 255;
    sprintf(buffer, "%X", decimal);
    printf("十进制%d → 十六进制字符串'%s'\n", decimal, buffer);
    
    return 0;
}
*/

//sscanf:是把一个字符串转化成一个格式化数据
//sprintf:是把一个格式化的数据转化成字符串
struct S
{
	char arr[10];
	int age;
	float score;
};
int main()
{
	struct S s={"zhangyuan",40,99.9f};
	struct S temp={0};
	char buf[100]={0};
	//把s中的格式化数据转化成字符串放到buf中
	sprintf(buf,"%s %d %f",s.arr,s.age,s.score);
	printf("字符串：%s\n",buf);
	
	//从字符串buf中获取一个格式化数据到temp中
	sscanf(buf,"%s %d %f",temp.arr,&(temp.age),&(temp.score));
	printf("格式化：%s %d %f\n",temp.arr,temp.age,temp.score);
	return 0;
}






















