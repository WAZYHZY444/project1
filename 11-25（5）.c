#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char arr[256];
	fgets(arr,sizeof(arr),stdin);
//fgets(字符数组名, 数组大小, stdin);
	//gets(arr);
//gets 函数在新标准中已经不推荐使用，因为它不安全（可能造成缓冲区溢出）。在实际编程中建议使用 fgets 或其他安全的方法。
	int num=strlen(arr);
	int count=0;
	for(int i=0;i<num;i++){
		if(arr[i]<='9'&&arr[i]>='0'){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}