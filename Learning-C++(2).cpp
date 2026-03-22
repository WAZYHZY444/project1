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

int main()
{
	test01();
}