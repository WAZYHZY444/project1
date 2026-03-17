#include <iostream>
using namespace std;


void test01()
{
	//在堆区创建整型数据
	//new返回的是该数据类型的指针
	int* p=new int(10); //创建了单个int对象，并初始化为值10
	cout<<*p<<endl;  //解引用
	//堆区的数据由程序员管理开辟，管理释放
	delete p;
//	cout<<*p<<endl;  //内存已经释放，再次访问就是非法操作，会报错
}

void test02()
{
	//创建有10个相同数据类型元素的数组，在堆区
	int* arr=new int[10];  //10代表数组有10个元素
	for(int i=0;i<10;i++){
		cin>>arr[i];
	}
	for(int i=0;i<10;i++){
		cout<<arr[i]<<endl;
	}
	//释放数组
	delete[] arr;
}

//引用的基本使用
//作用：给变量起别名
//语法：数据类型 &别名=原名
//注意事项：引用必须初始化，引用在初始化后，不可以改变(更改成其他变量的别名)
//引用的本质就是一个指针常量
void test03()
{
	int a=10;
	int &b=a;  //自动转换为int* const b=&a;
	b=20;     //a和b使用的是同一块内存空间
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
}

//引用做函数参数
//作用：函数传参时，可以利用引用的技术修饰实参
void test04(int &a,int &b)  //引用传递，形参会修饰实参(相当于是给实参取别名)
{
	int temp=a;
	a=b;
	b=temp;
}

//引用做函数的返回值
//1.不要返回局部变量的引用
//int& test05()
//{
//	int a=10;
//	return a;  //局部变量，出了函数就被销毁了
//}

int& test06()
{
	static int a=20;  //静态变量，存放在全局区，全局区上的数据在程序结束后释放
	return a;
}

/*
int main()
{
	//test01();
	//test02();
	//test03();
//	int a=10;
//	int b=20;
//	test04(a,b);
//	cout<<"a="<<a<<endl;
//	cout<<"b="<<b<<endl;
	int &ref=test06();
	cout<<"ref="<<ref<<endl;
	test06()=30;
	//2.如果函数的返回值是引用，这个函数调用可以作为左值
	cout<<"ref="<<ref<<endl;  //ref是a的别名
	return 0;
}
*/

void test07(const int &val)  //常量引用，用来修饰形参，防止误操作
{
	a=100; //报错，不能修改参数
}
int main()
{
	int a=10;
	//int &ref=10;  //引用必须引用一块合法内存空间(栈区、堆区)，而常量在常量区
	const int &ref=10;  //加上const之后，编译器创建了一个临时变量，ref是该临时变量的别名
	ref=20;  //加上const之后变成只读，不能修改
	int val=10;
	test07();
}
















