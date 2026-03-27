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

int main()
{
	test02();
	return 0;
}