#include <stdio.h>
#include <string.h>
//memcpy可以复制各种类型的数据
/*
int main()
{
	float arr1[5]={1.0,2.4,4.3,4.6,5.7};
	float arr2[10]={0.0};
	memcpy(arr2,arr1,sizeof(arr1));
//目标空间，源字符串，要复制的字节数(不是只能复制整个数组，可以从任意的位置复制任意字节数，但要注意复制的字节数除以数据类型要是整数)
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