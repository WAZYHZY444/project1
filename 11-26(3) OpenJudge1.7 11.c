#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[150];
	char arr2[150];
	char arr3[150];
	scanf("%s%s%s",arr1,arr2,arr3);
	int num1=strlen(arr1);
	//int num2=strlen(arr2);
	int num3=strlen(arr3);
	//第一步：先检查映射关系是否正确
	for(int i=0;i<num1;i++){
		for(int j=0;j<num1;j++){
			if(arr2[i]==arr2[j]&&arr1[i]!=arr1[j]){
				printf("Failed\n");
				return 0;
			}
			if(arr2[i]!=arr2[j]&&arr1[i]==arr1[j]){
				printf("Failed\n");
				return 0;
			}
		}
	}
	// 第二步：检查是否26个字母都出现了
    int all_letters[26] = {0};  // 标记26个字母是否出现
    for(int i = 0; i < num1; i++) {
        all_letters[arr1[i] - 'A'] = 1;  // 标记出现的字母
    }
    
    // 检查是否有字母没出现
    for(int i = 0; i < 26; i++) {
        if(all_letters[i] == 0) {
            printf("Failed\n");
            return 0;
        }
    }
    //第三步：翻译信息
	for(int i=0;i<num3;i++){
		int found=1;
		for(int j=0;j<num1;j++){
			if(arr3[i]==arr1[j]){
				arr3[i]=arr2[j];
				found=0;
				break;
			}
		}
		if(found){
			printf("Failed\n");
			return 0;
		}
	}
	
	printf("%s\n",arr3); 
	return 0;
}