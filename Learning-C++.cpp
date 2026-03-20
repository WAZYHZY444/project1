#include <iostream>
#include <string>
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

/*
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
*/

//函数的默认参数：用法与python差不多，注意：如果函数声明和函数的实现只能有一个地方有默认参数
//函数占位参数：返回值类型 函数名 (数值类型) {}
void func1(int a,int){
	cout<<"this is func"<<endl;
}

//函数重载：可以让函数名相同，提高复用性
//满足条件：1.同一作用域下
//          2.函数名称相同
//          3.函数参数类型不同或者个数不同或者顺序不同
//注意：函数的返回值不可以作为函数重载的条件

//函数重载注意事项：
//1.引用作为重载的条件
void func(int &a){
	cout<<"func(int &a)函数调用"<<endl;
}
void func(const int &a){
	cout<<"func(const int &a)函数调用"<<endl;
}

//2.函数重载遇到默认参数
void func2(int a,int b=10){
	cout<<"func(int &a)函数调用"<<endl;
}

void func2(int a){
	cout<<"func(int &a)函数调用"<<endl;
}
/*
int main()
{
	//func1(10,10);
//	int a=10;
//	func(a);
//	func(10);
	func2();   //函数重载遇到默认参数,容易出现二义性，需要避免
	return 0;
}
*/

//类中的属性和行为，统一称为成员
//属性->成员属性、成员变量
//行为->成员函数、成员方法
class Peo{
public:
	//属性
	string name;
	int age;
	//行为
	void ShowInfo(){
		cout<<"姓名："<<name<<"    年龄："<<age;
	}
	//通过行为给属性赋值
	void SetInfo(string m_name,int m_age){
		name=m_name;
		age=m_age;
	}
};

//把属性和行为放在不同的权限下，加以控制
//访问权限有三种：1.public     公共权限   成员在类内、类外可以访问
//                2.protected  保护权限   类内可以访问，类外可以访问，儿子可以访问父亲中保护内容
//                3.private    私有权限   类内可以访问，类外可以访问，儿子不可以访问父亲私有内容

//struct和class的区别：
//··struct默认权限为公共
//··class默认权限为私有

//构造函数：作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无序手动调用
//析构函数：作用在于对象销毁前系统自动调用，执行一些清理工作
//构造和析构都是必须有的实现，如果自己不提供，编译器会提供一个空的构造和析构

//构造函数：
//1.没有返回值，也不写void
//2.函数名与类名相同
//3.可以有参数，因此可以发生重载
//3.程序在调用对象时会自动调用构造，无需手动调用，而且只会调用一次
//析构函数：
//1.没有返回值，也不写void
//2.函数名与类名相同，在名称前加上符号~
//3.不可以有参数，因此不可以发生重载
//3.程序在调用对象时会自动调用构造，无需手动调用，而且只会调用一次

class Person{
public:
	Person(){
		cout<<"构造函数"<<endl;
	}
	~Person(){
		cout<<"析构函数"<<endl;
	}
};

void test08(){
	Person p;  //在栈上的数据，test01执行完毕后，释放这个对象
}

class Per{
public:
	int age;
	//无参构造
	Per(){
		cout<<"构造函数"<<endl;
	}
	//有参构造(默认构造)
	Per(int a){
		age=a;
		cout<<"有参构造函数"<<endl;
	}
	//析构
	~Per(){
		cout<<"析构函数"<<endl;
	}
	//拷贝构造
	Per(const Per &b){
		age=b.age;
		cout<<"拷贝构造函数"<<endl;
	}
};
//调用
void test09()
{
	//1.括号法
//	Per p1;      //默认构造函数调用
//	Per p2(10);  //有参构造调用
//	Per p3(p2);  //拷贝构造
	//注意事项1：调用默认构造函数时，不要加()
	//          因为编译器会认为是一个函数的声明，不会认为在创建对象
	
//	cout<<"p2的年龄:"<<p2.age<<endl;
//	cout<<"p2的年龄:"<<p2.age<<endl;

	//2.显式法
//	Per q1;
//	Per q2=Per(20);
//	Per q3=Per(q2);
	//注意事项2：不要利用拷贝构造函数初始化匿名对象,编译器会认为Per(q3)-->Per q3(无参构造)，就会认为发生重定义
	//Per(q3);
	//Per(20) --->匿名对象(当前行执行后，系统会立即回收掉匿名对象)
//	Per(20);
//	cout<<"结束"<<endl;   //在调用了析构函数之后才执行

	//3.隐式转换法
	Per q4=10;   //相当于Per q4=Per(10)
	Per q5=q4;
}
int main()
{
	//实例化对象(创建一个对象)
	Peo s1;
	//方式一：
//	s1.name="ZhangYuan";
//	s1.age=40;
	//方式二:
//	s1.SetInfo("SuXing",41);
//	s1.ShowInfo();

	//test08();
	//Person p;
//system("pause"); 后面的代码确实不会执行，程序会暂停在这一行，只有当你按下任意键后，才会继续执行后面的代码。
	//system("pause");
	
	test09();
	return 0;
}








