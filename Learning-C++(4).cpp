//STL(standard template librery)
//STL六大组件：容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器

#include <iostream>
#include <string>
using namespace std;
#include <algorithm>  //标准算法头文件
//容器vector   算法for_each   迭代器vector<int>::iterator
#include <vector>

void myPrint(int val){
	cout<<val<<endl;
}
                        //****vector容器存放内置数据类型****//
void test01(){
	//创建一个vector容器
	vector<int> v;
	//向容器中插入元素
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
//	//通过迭代器访问容器中的数据
//	vector<int>::iterator itBegin=v.begin();   //起始迭代器，指向容器中第一个元素
//	vector<int>::iterator itEnd=v.end();       //结束迭代器，指向容器中最后一个元素的下一个位置
//
//	//第一种遍历方式
//	while(itBegin!=itEnd){
//		cout<<*itBegin<<endl;
//		itBegin++;
//	}
	
//	//第二种遍历方式
//	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
//		cout<<*it<<endl;
//	}

	//第三种遍历方式（利用STL提供的）
	for_each(v.begin(),v.end(),myPrint);
}

					//****vector容器中存放自定义数据类型 类****//
class Person{
public:
	string name;
	int age;
	
	Person(string m_name,int m_age){
		name=m_name;
		age=m_age;
	}
};
	
void test02(){
	vector<Person> v;
	Person p1("ZhangYuan",40);
	Person p2("SuXing",41);
	Person p3("LuHu",39);
	//向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	//遍历容器中的数据
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
		cout<<"姓名："<<it->name<<"年龄："<<it->age<<endl;
	}
}

				//****vector容器中存放自定义数据类型 指针****//
void test03(){
	vector<Person*> v;
	Person p1("ZhangYuan",40);
	Person p2("SuXing",41);
	Person p3("LuHu",39);
	//向容器中添加数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	//遍历容器中的数据
	for(vector<Person*>::iterator it=v.begin();it!=v.end();it++){
		cout<<"姓名："<<(*it)->name<<"年龄："<<(*it)->age<<endl;
	}
}			

				//****vector容器嵌套vector容器****//
void test04(){
	vector<vector<int>> v;
	//创建小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	//向小容器添加数据
	for(int i =0;i<3;i++){
		v1.push_back(i+1);
		v2.push_back(i+2);
		v3.push_back(i+3);
	}
	//将小容器插入到大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	//通过大容器，把所有数据遍历一遍
	for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++){
		for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++){
			cout<<*vit<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	test04();
	return 0;
}
