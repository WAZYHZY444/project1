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
//                2.protected  保护权限   类内可以访问，类外可以访问，儿子再类内可以访问父亲中保护内容，在子类类外(外部对象)不可以访问
//                3.private    私有权限   类内可以访问，类外不可以访问，儿子不可以访问父亲私有内容

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
	int *height;
	//无参构造
	Per(){
		cout<<"无参构造函数"<<endl;
	}
	//有参构造(默认构造)
	Per(int a){
		age=a;
		cout<<"有参构造函数"<<endl;
	}
	//析构函数
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
	Per p1;      //默认构造函数调用
	Per p2(18);  //有参构造调用
	Per p3(p2);  //拷贝构造
	//注意事项1：调用默认构造函数时，不要加()
	//          因为编译器会认为是一个函数的声明，不会认为在创建对象
	
//	cout<<"p2的年龄:"<<p2.age<<endl;
//	cout<<"p2的年龄:"<<p2.age<<endl;

	//2.显式法
	Per q1;
	Per q2=Per(20);
	Per q3=Per(q2);
	//注意事项2：不要利用拷贝构造函数初始化匿名对象,编译器会认为Per(q3)-->Per q3(无参构造)，就会认为发生重定义
	//Per(q3);
	//Per(20) --->匿名对象(当前行执行后，系统会立即回收掉匿名对象)
//	Per(20);
//	cout<<"结束"<<endl;   //在调用了析构函数之后才执行

	//3.隐式转换法
	Per q4=10;   //相当于Per q4=Per(10)
	Per q5=q4;
}


//拷贝函数调用时机：
//1.使用一个已经创建完毕的对象来初始化一个新对象
void test10(){
	Per p1(10);
	Per p2(p1);
	cout<<"p2的年龄:"<<p2.age<<endl;
}
//2.值传递的方式给函数参数传值
void doWork(Per p){
	
}
void test11(){
	Per p;
	doWork(p);
}
//3.值的方式返回局部对象(dev-C++好像并没有调用拷贝函数，p1和p的地址相同)
Per doWork2(){
	Per p1;
	cout<<(int*)&p1<<endl;
	return p1;
}
void test12(){
	Per p=doWork2();
	cout<<(int*)&p<<endl;
}

//如果定义了有参构造函数，C++不再提供默认无参构造，但会提供默认拷贝构造
//如果定义了拷贝构造函数，C++不再提供其他构造函数

class Ren{
public:
	int age;
	int* height;
	
	Ren(int m_age,int m_height){
		age=m_age;
		height=new int(m_height);
	}
	//如果属性有在堆区开辟的，要自己实现拷贝构造函数，解决浅拷贝带来的问题
	Ren(const Ren &p){
		age=p.age;
		//height=p.height;  编译器默认拷贝函数实现的就是这行代码
		height=new int(*p.height);
	}
	~Ren(){
		//析构代码，将对堆区开辟的数据释放
		if(height!=NULL){
			delete height;
			height=NULL;
		}
	}
};

void test13()
{
	Ren p1(40,182);
	cout<<"p1的年龄:"<<p1.age<<"  身高:"<<*p1.height<<endl;
	Ren p2(p1);
	cout<<"p2的年龄:"<<p1.age<<"  身高:"<<*p1.height<<endl;
	//Per p2(p1)如果利用编译器提供的拷贝构造函数，会做浅拷贝操作
	//浅拷贝操作带来的问题是堆区的内存重复释放，需要利用深拷贝解决
}

//初始化列表
class Test01{
public:
	int A;
	int B;
	int C;
	
//	Test01():A(10),B(20),C(30){
//
//	}
	Test01(int a,int b,int c):A(a),B(b),C(c){
		
	}
};

//类对象作为类成员
class Phone{
public:
	string pname;
	Phone(string m_pname){
		pname=m_pname;
	}
};

class Test02{
public:
	string name;
	Phone phone;
	
	Test02(string m_name,string m_pname):name(m_name),phone(m_pname){ //Phone pone=m_pname(隐式转换法)
		
	}
};
//当其它类的对象作为本类，构造时先构造类对象，在构造自身；析构顺序与构造相反
void test14()
{
	Test02 p("ZhangSan","huawei");
	cout<<p.name<<"拿着"<<p.phone.pname<<endl;
}

//静态成员变量
//1.所有对象都共享同一份数据
//2.编译阶段就分配内存
//3.类内声明，类外初始化操作
class Test03{
public:
	static int A;
//静态成员变量也是有权限的
private:
	static int B;
};

int Test03::A=100;  //类外初始化操作
int Test03::B=200;

void test15()
{
	Test03 p;
	cout<<p.A<<endl;
	
	Test03 p2;
	p2.A=200;
	cout<<p.A<<endl;
}

void test16()
{
	//静态成员变量不属于某个对象，所有对象都共享同一份数据，因此静态成员变量有两种访问方式
	//1.通过对象进行访问
	Test03 p;
	cout<<p.A<<endl;
	//2.通过类名进行访问
	cout<<Test03::A<<endl;
//	cout<<Test03::A<<endl;   类外访问不到私有的静态成员变量
}


//静态成员函数(静态成员变量也是有权限的)
//1.所有对象共享同一个函数
//2.静态成员函数只能访问静态成员变量
class Test04{
public:
	static int A;
	int B;
	static void func(){
		A=100;  //静态成员函数可以访问静态成员变量
//		b=200;  静态成员函数不可以访问非静态成员变量
		cout<<"static void func调用"<<endl;
	}
};
int Test04::A=0;
void test17()
{
	//静态成员函数调用有两种方式
	//1.通过对象访问
	Test04 p;
	p.func();
	//2.通过类名访问
	Test04::func();
}


//成员变量和成员函数分开存储
class Test05{
	
};
class Test06{
	int A;   //非静态成员变量，属于类的对象上
	static int B;  //静态成员变量，不属于类的对象上
	void func(){}  //非静态成员函数，不属于类的对象上
	static void func2(){}  //静态成员函数，不属于类的对象上
	
};
void test18()
{
	Test05 p;
	//空对象所占内存空间为1
	//C++编译器会给每个空对象分配一个字节的空间，是为了区分空对象占内存的位置
	//每个空对象有独一无二的内存地址
	cout<<"size of p="<<sizeof(p)<<endl;
}
void test19()
{
	Test06 p;
	cout<<"size of p="<<sizeof(p)<<endl;
}

//this指针的用途：
//1.在形参和成员变量同名时，用this指针区分
//2.在类的非静态成员函数中返回对象本身，可开始用return *this
class Test07{
public:
	int age;
	Test07(int age){
		//this指针指向被调用的成员函数所属的对象
		this->age=age;
	}
	Test07& AddAge(Test07 &p){ //如果返回不加引用，返回的是值，那每次调用函数都会创建新的对象，不会对连续地对本体进行修改
		this->age+=p.age;
		return *this;  //this是指向对象的指针，而*this指向的就是这个对象本体
	}
};
void test20(){
	Test07 p(10);
	cout<<"age="<<p.age<<endl;
}
void test21(){
	Test07 p1(10);
	Test07 p2(10);
	p2.AddAge(p1).AddAge(p1).AddAge(p1);
	cout<<"p2 age="<<p2.age<<endl;
}

//常函数
//this指针的本质是指针常量，指针的指向是不能修改的
class Test08{
public:
	int A=0;
	mutable int B=0;  //特殊变量，加上mutable关键字就可以修改了
	//在成员函数后面加上const，修饰的是this指向，让指针指向的值也不可以修改了
	void func() const {  //const Test08* const this  -->不可以修改指针指向对象的值了
//		this->A=100;
		this->B=200;
		cout<<"B="<<B<<endl;
	}
};
void test22()
{
	Test08 p;
	p.func();
}
void test23()
{
	const Test08 p;  //常对象
//	p.A=100;
	p.B=300;  //B是特殊变量，在常对象下也可以修改
	cout<<"B="<<p.B<<endl;
	//常对象只能调用常函数
}

//友元的目的：让一个函数或者类访问另一个类中的私有成员
//全局函数做友元
class Test09{
	friend void Func(Test09* person);
public:
	string name="ZhangSan";
private:
	int ID=123252;
};

void Func(Test09* person)
{
	cout<<"正在访问名字:"<<person->name<<endl;
	cout<<"正在访问ID:"<<person->ID<<endl;
}
void test24(){
	Test09 p;
	Func(&p);
}

//类做友元
class Identity{
	friend class Test10;
public:
	string name;
	Identity();
private:
	int ID;
};

class Test10{
public:
	Test10();
	~Test10();
	Identity* identity; //有一个指针类型的成员变量
	
	void visit();  //访问函数
};

//类外写成员函数
Identity::Identity(){
	name="ZhangSan";
	ID=1342;
}
//给Test10里面的identity指针开辟一块空间，大小正好存放一个Identity类型的对象
Test10::Test10(){
	identity=new Identity;
}
Test10::~Test10(){
	delete identity;
}
void Test10::visit(){
	cout<<"正在访问名字:"<<identity->name<<endl;
	cout<<"正在访问ID:"<<identity->ID<<endl;
}

void test25()
{
	Test10 p;
	p.visit();
}

//成员函数做友元
//前向声明
class Iden;

class Test11{
public:
	Test11();
	~Test11();
	Iden* iden; //有一个指针类型的成员变量
	
	void visit();  //不可以访问Iden中的私有成员
	void Visit();  //可以访问Iden中的私有成员
	
	Test11(const Test11 &p){
		iden=new Iden(*p.iden);
	}
};

class Iden{
	friend void Test11::Visit();
public:
	string name;
	Iden();
	//添加拷贝构造函数
private:
	int ID;
};

Iden::Iden(){
	name="ZhangSan";
	ID=78565;
}
Test11::Test11(){
	iden=new Iden;
}
Test11::~Test11(){
	delete iden;
}
void Test11::visit(){
	cout<<"正在访问名字:"<<iden->name<<endl;
}
void Test11::Visit(){
	cout<<"正在访问ID:"<<iden->ID<<endl;
}

void test26()
{
	Test11 i;
	i.visit();
	i.Visit();
}
int main()
{
	//实例化对象(创建一个对象)
	//Peo s1;
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
	
	//test09();
	
	//test10();
	//test11();
	//test12();
	
	//test13();
	
	//Test01 t1;
//	Test01 t1(30,20,10);
//	cout<<"A="<<t1.A<<endl;
//	cout<<"B="<<t1.B<<endl;
//	cout<<"C="<<t1.C<<endl;

	//test14();
	
	//test15();
	//test16();
	
	//test17();
	
	//test18();
	//test19();
	
	//test20();
	//test21();
	
	//test22();
	//test23();
	
	//test24();
	//test25();
	test26();
	return 0;
}