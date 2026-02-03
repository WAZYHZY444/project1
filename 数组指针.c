/*
#include <stdio.h>
int main()
{
	char* arr[5]={0}; //pc指向的是arr数组，arr数组的每个元素的类型是char*
	char* (*pc)[5]=&arr; //注意此处[]里的数值不能省略
}     //数组在传参时，形参可以写成数组的形式，但实际上编译器会将其转换为指针
*/

#include <stdio.h>
void print(int(*p)[5],int r,int c)  //数组传参传的是首元素地址，二维数组的首元素地址是第一行的所有元素，可以看作是一个一维数组的整个数组，可以使用指向一维数组的指针
{
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%d ",*(*(p+i)+j) );//p+i指向某一行的地址，*（p+i)表示拿到了这一行的数组名。数组名有相当于首元素的地址，*(p+i)+j表示这一行下标为j元素的地址
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5]={1,2,3,4,5,2,3,4,5,6,3,4,5,6,7};
	print(arr,3,5);
	return 0;
}
