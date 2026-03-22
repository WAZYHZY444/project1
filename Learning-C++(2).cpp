#include <iostream>
#include <string>

using namespace std;

//运算符重载
class Test01{
public:
	int A;
	int B;
	
//	//1.成员函数重载+号
//	Test01 operator+ (Test01 &T)
//	{
//		Test01 temp;  //创建一个临时对象
//		temp.A=this->A+T.A;
//		temp.B=this->B+T.B;
//		return temp;
//	}
};

//全局函数重载+号
Test01 operator+ (Test01 &T1,Test01 &T2)
{
	Test01 temp;
	temp.A=T1.A+T2.A;
	temp.B=T1.B+T2.B;
	return temp;
}

void test01(){
	Test01 t1;
	t1.A=10;
	t1.B=20;
	Test01 t2;
	t2.A=10;
	t2.B=30;
	Test01 t3=t1+t2;
	//成员函数重载调用本质
//	Test01 t3=t1.operator+(t2);
	//成员函数重载调用本质
//	Test01 t3=operator+(t1,t2);

	cout<<"t3.A="<<t3.A<<endl;
	cout<<"t3.B="<<t3.B<<endl;
}


class Test02{
public:
	int A;
	int B;
};

//只能利用全局函数重载左移运算符
ostream& operator<<(ostream &cout,Test02 &T)  //返回类型是引用相当于返回的是地址不是值(链式调用)
{
	cout<<"A="<<T.A<<"   B="<<T.B;
	return cout;
}
void test02()
{
	Test02 t;
	t.A=10;
	t.B=20;
	cout<<t<<endl;
}

class Test03{
public:
	int num=10;	
	
	//重载前置++运算符
	Test03& operator++()
	{
		num++;
		return *this;
	}
	//重载后置++运算符
	Test03 operator++(int) //int是占位参数，可以区分前置和后置递增
	{
		Test03 temp=*this;
		num++;
		return temp;
	}
	//前置递减
	Test03& operator--()
	{
		num--;
		return *this;
	}
	//后置递减
	Test03 operator--(int)
	{
		Test03 temp=*this;
		num--;
		return temp;
	}
};

//ostream& operator<<(ostream& cout,Test03 T)   //传值，会拷贝一份对象
ostream& operator<<(ostream& cout,const Test03& T)
{
	cout<<T.num;
	return cout;
}


void test03()
{
	Test03 t;
	cout<<"t++="<<t++<<"   t="<<t<<endl;
	cout<<"++t="<<++t<<"   t="<<t<<endl;
	
	cout<<"t--="<<t--<<"   t="<<t<<endl;
	cout<<"--t="<<--t<<"   t="<<t<<endl;
}

int main()
{
	test03();
	return 0;
}
