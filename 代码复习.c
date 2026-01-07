//0到100的素数
/*
#include <stdio.h>
int main()
{
	for(int i=2;i<=100;i++){
		int mark=1;
		for(int j=2;j*j<=i;j++){   //重大发现：j*j要<=i(不要忘记=）
			if(i%j==0){  //不是素数
				mark=0;
				break;
			}
		}
		if(mark){
			printf("%d ",i);
		}
	}
	return 0;
}
*/

//前50个素数
/*
#include<stdio.h>
int main()
{
//	int count=0;
//	for(int i=2;i<=1000;i++){
//		int mark=1;
//		for(int j=2;j*j<=i;j++){
//			if(i%j==0){
//				mark=0;
//				break;
//			}
//		}
//		if(mark){
//			printf("%d ",i);
//			count++;
//		}
//		if(count==50)break;
//	}

//调整版
	int count=0;
	for(int i=2;count<50;i++){
		int mark=1;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				mark=0;
				break;
			}
		}
		if(mark){
			printf("%d ",i);
			count++;
		}
	}
	return 0;
}
*/

//九九乘法表
/*
#include <stdio.h>
int main()
{
	for(int i=1;i<10;i++){
		for(int j=1;j<=i;j++){
			printf("%d*%d=%-2d   ",i,j,i*j);
		}
		printf("\n");
	}
	return 0;
}
*/

//整数的分解
/*
#include <stdio.h>
void test(int x)
{
	if(x>9){  //递归优先考虑递归条件，思考什么样的条件需要重复调用函数，当不满足条件是需要做什么
		test(x/10);  
	}
	printf("%d ",x%10);
}
int main()
{
	int x;
	scanf("%d",&x);
	test(x);
	return 0;
}
*/

//计算整数的位数
/*
#include <stdio.h>  //12345
int main()
{
	int n;
	int count=0;
	scanf("%d",&n);
	while(n>0){
		n/=10;
		count++;
	}
	printf("%d\n",count);
}
*/

//打印三角形
/*
#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	char c1=' ';
	char c2='*';
	for(int i=1;i<=n;i++){   //i表示行号
		int C1=n-i;
		int C2=2*i-1;
		while(C1>0){
			printf("%c",c1);
			C1--;
		}
		while(C2>0){
			printf("%c",c2);
			C2--;
		}
		printf("\n");
	}
	return 0;
}
*/

//二分法递归求解零点
/*
#include <stdio.h>
#include <math.h>
double f(double x)
{
	return x*x*x-exp(-x);
}

double test(double left,double right)
{
	double mid=(left+right)/2;
	if(fabs(right-left)<1e-6||fabs(f(mid))<1e-6){
		return mid;
	}
	if(f(mid)<0){
		return test(mid,right);
	}else{
		return test(left,mid);
	}
}
int main()
{
	double ret=test(0.0,1.0);
	printf("%.3f\n",ret);
	return 0;
}
*/

//二分查找  需要先排序
//迭代
/*
#include <stdio.h>
int test(int arr[],int key,int sz)
{
	int left=0,right=sz-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(key==arr[mid])return mid;
		if(key>arr[mid]){
			left=mid+1;
		}else right=mid-1;
	}
	return -1;
}
int main()
{
	int key=5;
	int arr[10]={2,4,5,6,7,8,9,10,12,13};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int ret=test(arr,key,sz);
	printf("%d\n",ret);
}
*/
//递归
/*
#include <stdio.h>
int test(int arr[],int key,int left,int right)
{
	int mid=(left+right)/2;
	if(key==arr[mid])return mid;
	if(key>arr[mid]){
		return test(arr,key,mid+1,right);
	}else return test(arr,key,left,mid-1);
	if(left>right)return -1;
}
int main()
{
	int key=5;
	int arr[10]={2,4,5,6,7,8,9,10,12,13};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int left=0,right=sz-1;
	int ret=test(arr,key,left,right);
	printf("%d\n",ret);
}
*/

//字符串中寻找最先出现的出现次数最多的字符
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[50];
	scanf("%s",arr);
	int len=strlen(arr);
	int dest[26]={0};
	for(int i=0;i<len;i++){
		int j=arr[i]-'a';
		dest[j]++;
	}
	int max=dest[0];
	for(int j=0;j<26;j++){
		if(dest[j]>max){
			max=dest[j];   //找出现的最大次数
		}
	}
	for(int j=0;j<26;j++){
		if(dest[j]==max){  //找最先出现最大次数所对应的字母
			printf("%c\n",j+'a');
			break;
		}
	}
	return 0;
}
//认识：花括号会创建一个新的作用域，在花括号里面定义的变量，除了花括号变量销毁，注意，不仅仅是函数，也可以是循环，
//所以在循环里面使用的变量需要在循环外面声明，并初始化，否则会返回初始值
//初始化变量

*/


//越界访问数组
/*
#include <stdio.h>
int main()
{
	int arr[2][2]={{1,2},{3,4}};
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/

//函数指针运用
/*
#include <stdio.h>
int Add(int x,int y){
	return x+y;
}

int Cal(int(*pf)(int,int))   //pf为函数指针
{
	int a=2,b=3;
	int ret=pf(a,b);
	printf("%d\n",ret);
}

int main()
{
	Cal(Add);
	return 0;
}
*/

//函数指针数组：存放函数指针的数组
/*
#include <stdio.h>
int Add(int a,int b)
{
	return a+b;
}

int Sub(int a,int b)
{
	return a-b;
}

int Mul(int a,int b)
{
	return a*b;
}

int Div(int a,int b)
{
	return a/b;
}

int main()
{
	int(*arr[4])(int,int)={Add,Sub,Mul,Div};
	int input;
	scanf("%d",&input);
	int x,y;
	scanf("%d %d",&x,&y);
	printf("%d\n",arr[input](x,y));   //注意该怎么调用函数
	return 0;
}
*/

//qsort的复习
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct singer
{
	char name[20];
	int age;
}singer;

int cmp_int(const void* e1,const void* e2)
{
	return (*(int*)e1-*(int*)e2);
}

int cmp_singerByname(const void* e1,const void* e2)
{
	return (strcmp(((singer*)e1)->name,((singer*)e2)->name));
}

int cmp_singerByage(const void* e1,const void* e2)
{
	return (((singer*)e1)->name-((singer*)e2)->name);
}

//相当于把冒泡排序拆成了两个函数进行，一部分调用compare函数，一部分进行交换
void Swap(char* ptr1,char* ptr2,int width)
{
	for(int i=0;i<width;i++){  //一个字节一个字节的比较
		char temp=*ptr2;
		*ptr2=*ptr1;
		*ptr1=temp;
		ptr1++;
		ptr2--;
	}
}

//需要把数组里的元素一对一对的比较，所以my_qsort的主体是循环（冒泡排序的思想）
//调用my_sort函数传参是可以传任意返回类型的函数地址，但进入了my_sort函数，会把不论什么类型都强制转化为char*类型，所以在my_sort函数内调用Swap函数，Swap函数的参数列表就直接是char*类型了
int my_qsort(void* base,int sz,int width,int(*compare)(const void*,const void*))  //比较函数返回值为int类型，返回的是>0,<0,==0的数字
{
	for(int i=0;i<sz-1;i++){
		int mark=1;
		for(int j=0;j<sz-i-1;j++){
			if(compare((char*)base+j*width,(char*)base+(j+1)*width)>0){
				//交换
				Swap((char*)base+j*width,(char*)base+(j+1)*width,width);
			}	
		}
	}
}
void test1(void)
{
	int arr[10]={3,4,6,2,1,7,9,8,5,10};
	int sz=sizeof(arr)/sizeof(arr[0]);
	qsort(arr,sz,sizeof(arr[0]),cmp_int);
	for(int i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void test2(void)
{
	singer p[3]={{"Zhangyuan",40},{"Allen Su",41},{"Wangyuexing",36}};
	int sz=sizeof(p)/sizeof(p[0]);
	//qsort(p,sz,sizeof(p[0]),cmp_singerByname);
	qsort(p,sz,sizeof(p[0]),cmp_singerByage);
	for(int i=0;i<3;i++){
		printf("%s %d\n",p[i].name,p[i].age);
	}
}
void test3(void)
{
	int arr[10]={3,4,6,2,1,7,9,8,5,10};
	int sz=sizeof(arr)/sizeof(arr[0]);
	my_qsort(arr,sz,sizeof(arr[0]),cmp_int);
	for(int i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void test4(void)
{
	singer p[3]={{"Zhangyuan",40},{"Allen Su",41},{"Wangyuexing",36}};
	int sz=sizeof(p)/sizeof(p[0]);
	my_qsort(p,sz,sizeof(p[0]),cmp_singerByname);
	//my_qsort(p,sz,sizeof(p[0]),cmp_singerByage);
	for(int i=0;i<3;i++){
		printf("%s %d\n",p[i].name,p[i].age);
	}
}

int main()
{
//	test1();
//	test2();
	test3();
	test4();
	return 0;
}
*/

//my_strlen
/*
#include <stdio.h>
int my_strlen(char* ptr)
{
	int count=0;
	if(ptr!=NULL){
		while(*ptr!='\0'){
			count++;
			ptr++;
		}
	}
	return count;
}
int main()
{
	char arr[20];
	scanf("%[^\n]",arr);
	int len=my_strlen(arr);
	printf("%d\n",len);
	return 0;
}
*/

//my_strcpy
/*
#include <stdio.h>
char* my_strcpy(char* ptr1,const char* ptr2)
{
	char* ret=dest;
	while(*ptr1++=*ptr2++){
		;
	}
	return ret;
}
int main()
{
	char arr1[20];
	char arr2[30];
	scanf("%[^\n]",arr1);
	my_strcpy(arr2,arr1);
	printf("%s\n",arr2);
	return 0;
}
*/

//my_strcat
/*
#include <stdio.h>
#include <stdio.h>
char* my_strcat(char* ptr1,const char* ptr2)
{
	char* ret=ptr1;
	while(*ptr1!='\0'){
		ptr1++;
	}
	//加上一个空格
	*ptr1=' ';
	ptr1++;
	while(*ptr1++=*ptr2++){
		;
	}
	return ret;
}
int main()
{
	char arr1[20];
	char arr2[30];
	fgets(arr1,sizeof(arr1),stdin);
	for(int i=0;arr1[i]!='\0';i++){
		if(arr1[i]=='\n'){
			arr1[i]='\0';
			break;
		}
	}
	fgets(arr2,sizeof(arr2),stdin);
	for(int i=0;arr2[i]!='\0';i++){
		if(arr2[i]=='\n'){
			arr2[i]='\0';
			break;
		}
	}
	my_strcat(arr1,arr2);
	printf("%s\n",arr1);
	return 0;
}
*/

//strncpy
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[30]="xxxxxxxxxx";
	char arr2[20];
	fgets(arr2,sizeof(arr2),stdin);  //会复制一大堆的'\0'
	for(int i=0;arr2[i]!='\0';i++){
		if(arr2[i]=='\n'){
			arr2[i]='\0';
			break;
		}
	}
	strncpy(arr1,arr2,sizeof(arr1)-1);
	arr1[sizeof(arr1)-1]='\0';
	printf("%s\n",arr1);
	return 0;
}
*/

//大->小 tolower strlwr
//小->大 toupper strupr

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

//memcpy
/*
#include <stdio.h>
#include <string.h>
int main()
{
	float arr1[5]={1.0,2.4,4.3,4.6,5.7};
	float arr2[10]={0.0};
	memcpy(arr2,arr1+1,4*sizeof(float));
	for(int i=0;i<4;i++){
		printf("%.1f ",arr2[i]);
	}
	return 0;
}
*/

#include <stdio.h>
#include <string.h>
int main()
{
//strstr函数如果字串存在，返回字串在母串所在的地址；如果字串不存在，则返回空指针
	char arr1[]="hello world!";
	char arr2[]="llo world";
	char* ret=strstr(arr1,arr2);
	if(ret==NULL){
		printf("字串不存在\n");
	}else{
		printf("%s\n",ret);
	}
	return 0;
}
























