#include <stdio.h>
#include <string.h>
int main()
{
	int sum=0;
	int a=1;
	char arr[14];
	scanf("%s",arr);
	for(int i=0;i<12;i++){
		if(arr[i]>='0'&&arr[i]<='9'){
			sum+=(arr[i]-'0')*a;
			a++;
		}
	}
	int ret=sum%11;
	char ret_char;
//ret = 10 时，'0' + 10 = 58，这是字符 ':' 的ASCII码
//但ISBN标准要求校验位10用字符 'X' 表示（ASCII码 88）
	if(ret==10){
		ret_char='X';
	}else{
		ret_char=ret+'0';
	}
	
	if(arr[12]==ret_char){
		printf("Right\n");
	}else{
		arr[12]=ret_char;
		printf("%s\n",arr);
	}
	return 0;
}