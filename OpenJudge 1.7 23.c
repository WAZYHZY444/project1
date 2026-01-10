#include <stdio.h>
#include <string.h>
//一：
/*
int main()
{
	char arr[201];
	char brr[201]={'\0'};
	fgets(arr,sizeof(arr),stdin);
	arr[strcspn(arr,"\n")]='\0';
	int len=strlen(arr);
	int j=0;
	for(int i=0;i<len;i++){
		if(arr[i]!=' '){
			brr[j]=arr[i];
		}
		else if(arr[i]==' '){
			brr[j]=arr[i];
			while(i+1<len&&arr[i+1]==' '){    //学习：如何连续跳过
				i++;
			}
		}
		j++;
	}
	brr[j]='\0';
	printf("%s\n",brr);
	return 0;
}
*/

//二：
#include <stdio.h>
#include <string.h>
void test(char arr1[],char arr2[])
{
	int str1=strlen(arr1);
	int str2=strlen(arr2);
	char brr[str2+1];
	int k=0;
	for(int i=0;i<str2;i++){
		for(int j=0;j<str1;j++){
			if(arr2[i]==arr1[j]){
				i++;
			}else{
				brr[k]=arr2[i];
				k++;
				i++;
			}
		}
	}
	brr[k]='\0';
	printf("%s\n",brr);
}
int main()
{
	char arr1[1000];
	char arr2[1000];
	scanf("%s %s",arr1,arr2);
	test(arr1,arr2);
	return 0;
}