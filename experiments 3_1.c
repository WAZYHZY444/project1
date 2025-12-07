#include <stdio.h>
#include <string.h>
void test(char arr1[],char arr2[])
{
	int str1=strlen(arr1);
	int str2=strlen(arr2);
	int k=0;  //让后面删除相同字符后的arr1重新从下标为0开始输出字符
	for(int i=0;i<str2;i++){
		int p=0;
		for(int j=0;j<str1;j++){
			if(arr2[i]==arr1[j]){
				p=1; //表示找到了相同的字符
				break;
			}
		}
		if(!p){
			arr2[k]=arr2[i];  //把不相同的字符重新传给arr1
			k++;  //k移动到下一个空位置
		}
	}
	// 循环结束后，k指向第一个空位置
	arr2[k]='\0'; //在空位置写入结束符
	printf("%s\n",arr2);
}
int main()
{
	char arr1[1000];
	char arr2[1000];
	scanf("%s %s",arr1,arr2);
	test(arr1,arr2);
	return 0;
}