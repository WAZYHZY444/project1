#include <stdio.h>
int main()
{
	int n;
	int max_len=1,current_len=1;
	scanf("%d",&n);
	int arr[n];
	int brr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n-1;i++){
		if(arr[i]+1==arr[i+1]){
			current_len++;
			if(current_len>max_len){
				max_len=current_len;
			}
		}else{
			current_len=1;
//中断后，当前长度重新计算，但是最大长度保持，当当前长度再次大于最大长度时，最大长度再次更新
		}
	}
	printf("%d\n",max_len);
	return 0;
}