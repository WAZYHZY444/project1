#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int num;
	scanf("%d",&num);
	int mark=0;
	for(int i=0;i<n;i++){
		if(arr[i]==num){
			printf("%d\n",i+1);
			mark=0;
			break;
		}
	}
	if(!mark){
		return -1;
	}
	return 0;
}