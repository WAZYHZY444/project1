#include <stdio.h>
size_t my_strlen(const char* str)
{
	size_t count=0;
	if(str!=NULL){
		while(*str!='\0'){
		count++;
		str++;
		}
	}
	return count;
}
int main()
{
	char arr[20];
//键盘接受字符
	//用fgets需要注意的是字符串后面会有个换行符，需要手动去除，好处是字符串间可以有空格
	//用scanf遇到空格就会结束
	fgets(arr,sizeof(arr),stdin);
	for(int i=0;arr[i]!='\0';i++){
		if(arr[i]=='\n'){
			arr[i]=='\0';
			break;
		}
	}
	size_t len=my_strlen(arr);
	printf("%u\n",len);
	return 0;
}