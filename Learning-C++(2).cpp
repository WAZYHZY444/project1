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


class Test04{
public:
	int* age;
	
	Test04(int m_age){
		age=new int(m_age);
	}
	~Test04(){
		if(age!=NULL){
			delete age;
			age=NULL;
		}
	}
	//赋值运算符重载
	Test04& operator=(Test04 &p){
		//应该先判断是否有属性在堆区，如果有释放干净，再深拷贝
		if(age!=NULL){
			delete age;
			age=NULL;
		}
		age=new int(*p.age);
		//返回对象本身(链式调用)
		return *this;
	}	
};

void test04()
{
	Test04 p1(10);
	Test04 p2(20);
	Test04 p3(30);
	
	p1=p2=p3;
	cout<<"p1.age="<<*p1.age<<endl;
	cout<<"p2.age="<<*p2.age<<endl;
	cout<<"p3.age="<<*p3.age<<endl;
}

//关系运算符重载
class Test05{
public:
	string name;
	int age;
	
	Test05(string m_name,int m_age){
		name=m_name;
		age=m_age;
	}
	bool operator==(Test05 &p){
		if(this->name==p.name&&this->age==p.age){
			return true;
		}else{
			return false;
		}
	}
};

void test05(){
	Test05 p1("ZhangYuan",40);
	Test05 p2("SuXing",41);
	if(p1==p2){
		cout<<"p1==p2"<<endl;
	}else{
		cout<<"p1!=p2"<<endl;
	}
}

//函数调用运算符重载(仿函数)
class Test06{
public:
	int operator()(int num1,int num2){
		return num1+num2;
	}
};

void test06(){
	Test06 add;
	int ret=add(100,200);
	cout<<"ret="<<ret<<endl;
	//匿名函数对象(匿名对象调用)
	cout<<Test06()(10,20)<<endl;
}


//继承
//好处：减少重复的代码
//语法：class 子类 : 继承方式 父类
//子类也称为派生类，父类也称为基类

//继承方式
class Base1{
public:
	int A;
protected:
	int B;
private:
	int C;
};

//1.公共继承
class Son1:public Base1{
public:
	void func(){
		A=10;  //父类中的公共权限成员到子类中依然是公共权限
		B=10;  //父类中的保护权限成员到子类中依然是保护权限
//		C=10;  //父类中的私有权限成员，子类访问不到
	}
};
void Son1_test(){
	Son1 s;
	s.A=100;
//	s.B=200;  //父类的保护成员在子类类外(外部对象)不能被访问
}

//保护继承
class Son2:protected Base1{
public:
	void func(){
		A=10;  //父类中的公共权限成员到子类中变成了保护权限
		B=10;  //父类中的保护权限成员到子类中依然是保护权限
//		C=10;  //父类中的私有权限成员，子类访问不到
	}
};
void Son2_test(){
	Son2 s;
//	s.A=100;   //不能访问
//	s.B=200;  //不能被访问
}

//私有继承
class Son3:private Base1{
public:
	void func(){
		A=10;  //父类中的公共权限成员到子类中变成了私有权限
		B=10;  //父类中的保护权限成员到子类中变成了私有权限
//		C=10;  //父类中的私有权限成员，子类访问不到
	}
};
void Son3_test(){
	Son3 s;
//	s.A=100;   //不能访问
//	s.B=200;  //不能被访问
}

//继承中的对象模型
class Base2{
public:
	int A;
protected:
	int B;
private:
	int C;
};

class Son2_1:public Base2{
public:
	int p;
};

void Son2_1_test(){
	cout<<"size of Son2_1="<<sizeof(Son2_1)<<endl;  //16
}
//父类中所有的非静态成员属性都会被子类继承下去
//父类中私有成员属性是被编译器隐藏了，因此是访问不到的，但还是被继承了

//继承中构造和析构的顺序
//先构造父类，在构造子类，析构的顺序相反
class Base3{
public:
	Base3(){
		cout<<"Base3的构造函数"<<endl;
	}
	~Base3(){
		cout<<"Base3的析构函数"<<endl;
	}
};

class Son3_1:public Base3{
public:
	Son3_1(){
		cout<<"Son3_1的构造函数"<<endl;
	}
	~Son3_1(){
		cout<<"Son3_1的析构函数"<<endl;
	}
};

void Son3_1_test(){
	Son3_1 p;
}

//继承中同名成员处理
class Base4{
public:
	int A;
	Base4(){
		A=100;
	}
	void func(){
		cout<<"Base同名函数"<<endl;
	}
	void func(int a){
		cout<<"Base(int a)同名函数"<<endl;
	}
	static int B;
};
int Base4::B=200;

class Son4_1:public Base4{
public:
	int A;
	Son4_1(){
		A=200;
	}
	void func(){
		cout<<"Son同名函数"<<endl;
	}
	static int B;
};
int Son4_1::B=100;

void Son4_1_test(){
	Son4_1 p;
	cout<<"Son A="<<p.A<<endl;
	//如果通过子类对象访问父类中的同名成员，需要加作用域
	cout<<"Base A="<<p.Base4::A<<endl;
	
	p.func();  //直接调用，调用的是子类中的同名成员
	p.Base4::func();
	//要访问父类中被隐藏的同名成员函数，需要加作用域
	p.Base4::func(10);
	//同名静态成员属性
	//通过类名访问
	cout<<"Son B="<<Son4_1::B<<endl;
	//第一个::代表通过类名方式访问，第二个::代表访问父类作用于下的同名静态属性
	cout<<"Base B="<<Son4_1::Base4::B<<endl;
}

//多继承语法
//语法：class 子类 : 继承方式 父类1, 继承方式 父类2
//当两个父类出现了同名成员，访问时需要加作用域

//菱形继承
class Animals{
public:
	int age;
};
//继承之前加上关键词virtual变为虚继承，Animals称为虚基类
class Sheep:virtual public Animals{};
class Tuo:virtual public Animals{};
class Sheeptuo:public Sheep,public Tuo{
	
};

void A_Test(){
	Sheeptuo st;
	st.Sheep::age=18;
	st.Tuo::age=28;
	//当菱形继承，两个父类拥有相同数据，需要加以作用域区分
	//菱形继承有两份数据，造成资源浪费
	cout<<"st.Sheep::age="<<st.Sheep::age<<endl;
	cout<<"st.Tuo::age="<<st.Tuo::age<<endl;
	cout<<"st.age="<<st.age<<endl;  //虚继承之后，这行代码也可以实现
}

//多态
//静态多态：函数重载和运算符重载属于静态多态
//动态多态：派生类和虚函数实现运行时多态

//动态多态满足条件：
//1.有继承关系
//2.子类重写父类的虚函数(返回类型、函数名、参数列表完全一样)

//动态多态的使用：父类的指针或引用指向子类对象
class Test07{
public:
	//虚函数:实现地址晚绑定
	virtual void func(){
		cout<<"我是基类"<<endl;
	}
};
class Son_Test07:public Test07{
public:
	void func(){
		cout<<"我是派生类"<<endl;
	}
};
//地址早绑定，在编译阶段就确定了函数地址
//如果想要执行子类的func函数，就要让函数地址不能提前绑定，需要在运行阶段进行绑定(地址晚绑定)
void Func(Test07 &t){   //父类的指针或引用指向子类对象
	t.func();
}
void test07(){
	Son_Test07 son;
	Func(son);
}
void test7(){
	cout<<"size of Test07="<<sizeof(Test07)<<endl;
}
//创建虚函数，类内部结构发生那个变化，多了一个虚函数指针，指针指向虚函数表，当在子类重写了虚函数后，子类的虚函数表内部会替换成子类的虚函数地址

//利用多态开发的好处：
//1.结构组织清晰
//2.可读性更强
//3.利于前期和后期的扩展以及维护

//纯虚函数：virtual 返回值类型 函数名 (参数列表)=0;
//当类有了纯虚函数，这个类称为抽象类
//抽象类的特点：1.无法实例化对象
//              2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类

class Test08{
public:
	virtual void speak()=0;	
	//虚析构和纯虚析构必须要有具体的函数实现
	//有了纯虚析构,这个类也属于抽象类，不能实例化对象(可以定义指针，但必须指向子类对象)
	
	//虚析构，解决父类指针释放子类对象不干净的问题
//	virtual ~Test08(){
//		cout<<"父类(虚)析构函数"<<endl;
//	}
	//纯虚析构·
	virtual ~Test08()=0;
};

 Test08::~Test08(){
 	cout<<"父类(纯虚)析构函数"<<endl;
 }
 
class Num1:public Test08{
public:
	string *name;
	
	Num1(string m_name){   //构造函数
		name=new string(m_name);
	}
	void speak(){
		cout<<*name<<"说加油"<<endl;
	}
	~Num1(){
		if(name!=NULL){
			delete name;
			name=NULL;
		}
		cout<<"子类析构函数"<<endl;
	}
	//父类指针在析构时，不会调用子类中的析构函数，导致子类如果有堆区的属性，会发生内存泄漏
};
void test08(){
	Test08*p=new Num1("XiaoMing"); //p是父类指针，指向的是一个子类对象
	p->speak();
	delete p;
}

int main()
{
	test08();
	//test7();
	//Son4_1_test();
	//A_Test();
	return 0;
}


