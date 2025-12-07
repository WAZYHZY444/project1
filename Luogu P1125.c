#include <stdio.h>
#include <string.h>
int main()
{
	char word[101];
	scanf("%s",word);
	int num=strlen(word);
	int arr[26]={0};
	for(int i=0;i<num;i++){
		int j=word[i]-'a';
		arr[j]=arr[j]+1;
	}
	int max=0;
	int min=101; //注意：这里不能写arr[0]，有可能字母a没有出现，导致min=0，但是min最小也只能等于1
	for(int i=0;i<26;i++){
		if(arr[i]>0){  //注意：只考虑出现过的字母
			if(arr[i]<min){
			min=arr[i];
			}
		if(arr[i]>max){
			max=arr[i];
			}
		}
	}
	int n=max-min;
	int mark=0;
	if(n<2){
		mark=1;
	}
	for(int i=2;i*i<=n;i++){  //注意此处判断质数的循环条件
		if(n%i==0){
			mark=1;
			break;
		}
	}
	if(mark){
		printf("No Answer\n");
		printf("0\n");
	}else{
		printf("Lucky Word\n");
		printf("%d\n",n);
	}
	return 0;
}