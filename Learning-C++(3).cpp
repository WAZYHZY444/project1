#include <iostream>
#include <string>

using namespace std;

//C++编程思想：一是面向对象思想，二是泛型编程。泛型编程只要利用的技术就是模板
//模板的目的是为了提高复用性，将类型参数化
//模板机制：函数模板和类模板

//函数模板
template<typename T>  //typename可替换成class
void Swap(T &a,T &b){
	T temp=a;
	a=b;
	b=temp;
}

void test01()
{
	int a=10;
	int b=20;
	//自动类型推导
	Swap(a,b);
	//显示指定类型
	Swap<int>(a,b);
	cout<<"a="<<a<<"  b="<<b<<endl;
}

//普通函数与函数模板的区别：
//1.普通函数调用可以发生隐式类型转换
//2.函数模板用自动类型推导，不可以发生隐式类型转换
//3.函数模板用显示指定类型，可以发生隐式类型转换

template<typename T>
T Swap2(T a,T b){
	return a+b;
}

void test02()
{
	int a=10;
	char b='c';
	cout<<Swap2<int>(a,b)<<endl;  //显示指定类型
}

//1.如果普通函数模板和普通函数都可以调用，优先调用普通函数
//2.可以通过空模板参数列表强制调用函数模板
//3.如果函数模板可以产生更好的匹配，优先调用函数模板

class Person{
public:
	string name;
	int age;
	Person(string name,int age){
		this->name=name;
		this->age=age;
	}
};

template<class T>
bool Com(T &a,T &b){
	if(a==b){
		return true;
	}else{
		return false;
	}
}

//利用具体化Person的版本实现代码
template<> bool Com(Person &p1,Person &p2){
	if(p1.name==p2.name&&p1.age==p2.age){
		return true;
	}else{
		return false;
	}
}

void test03(){
	Person p1("ZhangSan",18);
	Person p2("LiSi",19);
	
	bool ret=Com(p1,p2);
	if(ret){
		cout<<"p1==p2"<<endl;
	}else{
		cout<<"p1!=p2"<<endl;
	}
}

//C++17之前类模板没有自动类型推导使用方式，只能使用显示指定类型
//类模板可以写默认模板参数
template<class Typename,class Typeage=int>
class Per{
public:
	Typename name;
	Typeage age;
	Per(Typename name,Typeage age){
		this->name=name;
		this->age=age;
	}
};

void test04(){
	Per<string>p("ZhangYuan",41);
	cout<<"name is "<<p.name<<"  age is "<<p.age<<endl;
}

//普通类中的成员函数一开始就可以创建
//类模板中的成员函数在调用时才创建

//类模板对象做函数参数
template<class T1,class T2>
class Test05{
public:
	T1 name;
	T2 age;
	Test05(T1 name,T2 age){
		this->name=name;
		this->age=age;
	}
};

//类模板实例出的对象，向函数传参的方式：
//1.指定传入类型
void Func_1(Test05<string,int>&p){
	cout<<"name="<<p.name<<"  age="<<p.age<<endl;
}
//2.参数模板化
template<class T1,class T2>
void Func_2(Test05<T1,T2>&p){
	cout<<"name="<<p.name<<"  age="<<p.age<<endl;
	cout<<"T1的类型为："<<typeid(T1).name()<<endl;
	cout<<"T2的类型为："<<typeid(T2).name()<<endl;
}
//3.整个类模板化
template<class T>
void Func_3(T &p){
	cout<<"name="<<p.name<<"  age="<<p.age<<endl;
	cout<<"T的类型为："<<typeid(T).name()<<endl;
}

void test05(){
	Test05<string,int>p("Zhangyuan",40);
//	Func_1(p);
//	Func_2(p);
	Func_3(p);
}

//类模板与继承
template<class T>
class Base{
public:
	T A;
};
class Son:public Base<int>{
public:
	Son(){
		A=10;
	}
};

void test06(){
	Son s1;
	cout<<"A="<<s1.A<<endl;
}

int main()
{
	test06();
	return 0;
}