#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bubble_sort(int arr[],int sz)
{
	for(int i=0;i<sz-1;i++){
		int flag=1;               //假设数组是有序的
		for(int j=0;j<sz-1-i;j++){
			if(arr[j]>arr[j+1]){
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				flag=0;
			}
		}
		if(flag){
			break;
		}
	}
}

//qsort使用快速排序的思想实现的一个函数，这个函数可以排序任何类型的数据
//void qsort (void* base,   //要排序的数据的起始位置
//			  size_t num,   //待排序的数据元素的个数
//			  size_t width,  //待排序的每个数据元素的大小(单位是字节)
//            int (*compar)(const void* e1,const void* e2));  //函数指针-比较函数(传参的时候需要传一个函数的地址，所以需要写一个函数)

//比较2个整型元素(e1指向一个整数，e2指向另外一个整数)
int cmp_int(const void* e1,const void* e2)
{
	return (*(int*)e1-*(int*)e2);       //把数组排成升序
	//return (*(int*)e2-*(int*)e1);     //把数组排成降序
}

//相当于把冒泡排序拆成了两个函数进行，一部分调用compare函数，一部分进行交换
void Swap(char* buf1,char* buf2,int width)
{
	for(int i=0;i<width;i++){    //一个字节一个字节的交换
		char tmp=*buf1;
		*buf1=*buf2;
		*buf2=tmp;
		buf1++;
		buf2++;
	}
}
//模拟实现qsort(冒泡排序的思想)
//需要把数组里的元素一对一对的比较，所以my_qsort的主体是循环（冒泡排序的思想）
//调用my_sort函数传参是可以传任意返回类型的函数地址，但进入了my_sort函数，会把不论什么类型都强制转化为char*类型，所以在my_sort函数内调用Swap函数，Swap函数的参数列表就直接是char*类型了
void qsort_bubble_sort(void* base, int sz, int width,int (*cmp)(const void* e1,const void* e2))
{
	for(int i=0;i<sz-1;i++){
		int flag=1;               //假设数组是有序的
		for(int j=0;j<sz-1-i;j++){
			if(cmp((char*)base+j*width,(char*)base+(j+1)*width)>0){   //待比较两个元素的地址
				//交换
				Swap((char*)base+j*width, (char*)base+(j+1)*width, width);
				flag=0;
			}
		}
		if(flag){
			break;
		}
	}
}

struct singer
{
	char name[20];
	int age;
};

int cmp_singer_by_name(const void* e1,const void* e2)
{
	return strcmp(((struct singer*)e1)->name,((struct singer*)e2)->name);   //一定要记得给(struct singer*)e1加上括号在进行成员访问，否则会出现优先级的错误
}

int cmp_singer_by_age(const void* e1,const void* e2)
{
	return ((struct singer*)e1)->age-((struct singer*)e2)->age;
}


void test1()
{
	int arr[]={3,6,5,9,8,2,7,1,4,10};
	int sz=sizeof(arr)/sizeof(arr[0]);
	//bubble_sort(arr,sz);
	
	qsort(arr,sz,sizeof(arr[0]),cmp_int);
	
	for(int i=0;i<sz;i++){
		printf("%d ",arr[i]);
	}
}

void test2()
{
	//测试使用qsort来排序结构体数据
	struct singer s[]={{"zhangyuan",40},{"suxing",41},{"wangyuexing",36}};
	int sz=sizeof(s)/sizeof(s[0]);
	qsort(s,sz,sizeof(s[0]),cmp_singer_by_name);
	//qsort(s,sz,sizeof(s[0]),cmp_singer_by_age);
	for(int i=0;i<sz;i++){
		printf("%s %d\n",s[i].name,s[i].age);
	}
}

void test3()
{
	int arr[]={3,6,5,9,8,2,7,1,4,10};
	int sz=sizeof(arr)/sizeof(arr[0]);
	
	qsort_bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);
	
	for(int i=0;i<sz;i++){
		printf("%d ",arr[i]);
	}
}

void test4()
{
	//测试使用qsort来排序结构体数据
	struct singer s[]={{"zhangyuan",40},{"suxing",41},{"wangyuexing",36}};
	int sz=sizeof(s)/sizeof(s[0]);
	qsort_bubble_sort(s,sz,sizeof(s[0]),cmp_singer_by_name);
	//qsort_bubble_sort(s,sz,sizeof(s[0]),cmp_singer_by_age);
	for(int i=0;i<sz;i++){
		printf("%s %d\n",s[i].name,s[i].age);
	}
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}