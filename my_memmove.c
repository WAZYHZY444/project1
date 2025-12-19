#include <stdio.h>
#include <string.h>
void* my_memmove(void* dest,const void*src,size_t num)
{
	if(dest!=NULL&&src!=NULL){
		void*ret=dest;
		if(dest<src){  //从前向后拷
			while(num--){
				*(char*)dest=*(char*)src;
				dest=(char*)dest+1;
				src=(char*)src+1;
			}
		}else{        //从后向前拷
			while(num--){
				*((char*)dest+num)=*((char*)src+num);
			}
		}
		return ret;
	}
}
int main()
{
	int arr1[]={1,2,3,4,5,6,7,8,9,10};
	my_memmove(arr1+2,arr1,20);
	for(int i=0;i<10;i++){
		printf("%d ",arr1[i]);
	}
	return 0;
}