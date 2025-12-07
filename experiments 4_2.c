#include <stdio.h>
#include <string.h>
int main(){
	char ch[101];
	scanf("%s",ch);
	int num=strlen(ch);
	int arr[26]={0};
	for(int i=0;i<num;i++){
		int j=ch[i]-'a';
		arr[j]=arr[j]+1;
	}
	int max=arr[0];
	for(int i=0;i<26;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	for(int j=0;j<26;j++){
		if(arr[j]==max){
			printf("%c",j+'a');
			break;
		}
	}
	return 0;
}