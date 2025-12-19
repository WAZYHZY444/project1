#include <stdio.h>
#include <string.h>
/*
int main()
{
	float arr1[5]={1.0,2.4,4.3,4.6,5.7};
	float arr2[10]={0.0};
	memcpy(arr2,arr1,sizeof(arr1));
	return 0;
}
*/

void* my_memcpy(void* dest,const void* src,size_t num)
{
	if(dest!=NULL&&src!=NULL){
		void* ret=dest;
		
		while(num--){
			*(char*)dest=*(char*)src;  //类型强制转化为char*,char为1个字节，力度最小，避免num除不尽
			dest=(char*)dest+1;  //指针后移
			src=(char*)src+1;
		}
		return ret;
	}
}
int main()
{
	float arr1[5]={1.0,2.4,4.3,4.6,5.7};
	float arr2[10]={0.0};
	my_memcpy(arr2,arr1,sizeof(arr1));
	for(int i=0;i<5;i++){
		printf("%.1f ",arr2[i]);
	}
	return 0;
}