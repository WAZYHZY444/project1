#include <stdio.h>
//&&的短路规则：当&&的左边是0时，右边的不再执行；当&&左边非0，才会执行&&右边的
//&&：当两个数都为真（非0），返回1；否则返回0。所以直白来讲，i的值只能是1或0

/*
int main()
{
	int i=0,a=0,b=2,c=3,d=4;
	i=a++ && ++b && d++;    //注意运算符的优先级：i=((a++)&&(++b)&&(d++))
	//a++=0,&&右边不再执行
	printf("a=%d\nb=%d\nc=%d\nd=%d\n",a,b,c,d);
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int i=0,a=1,b=2,c=3,d=4;
	i=a++ && ++b && d++;
	//a++为真，继续执行，1&&3为真，继续执行，3%%4为真，继续执行   
	printf("a=%d\nb=%d\nc=%d\nd=%d\n",a,b,c,d);
	return 0;
}
*/

// ||的短路规则：当||左边是真时，右边不再执行
// ||：当有一个数为真（非0），返回1；否则返回0

/*
#include <stdio.h>
int main()
{
	int i=0,a=1,b=2,c=3,d=4;
	i=a++ || ++b || d++;     //逻辑短路
	printf("a=%d\nb=%d\nc=%d\nd=%d\n",a,b,c,d);
	return 0;
}
*/

#include <stdio.h>
int main()
{
	int i=0,a=0,b=2,c=3,d=4;
	i=a++ || ++b || d++;     //逻辑短路
	printf("a=%d\nb=%d\nc=%d\nd=%d\n",a,b,c,d);
	return 0;
}