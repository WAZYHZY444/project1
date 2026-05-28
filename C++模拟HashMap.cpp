#include <iostream>
#include <string>
using namespace std;

//前置声明Node结构体
template<class K,class V>
class Node{
public:
	K key;
	V value;
	Node<K,V>* next;
	Node(K k,V v):key(k),value(v),next(nullptr){}
};

template<class K,class V>
class HashMap{
private:
	int tableSize;   //哈希表的大小
	int elements;    //放入表中的元素数量
	Node<K,V>** table; //哈希表
	float loadFactor;  //负载因子，用于重新散列
	
	int hashCode(K key){  //哈希函数，对输入key计算在哈希表中的入口位置
		return key%tableSize;
	}
	
	void resizeTable(){  //重新散列哈希表
		int oldSize=tableSize;
		tableSize*=2;
		Node<K,V>** newTable=new Node<K,V>*[tableSize];
		for(int i=0;i<tableSize;i++){
			newTable[i]=nullptr;
		}	
		//遍历旧表
		for(int i=0;i<oldSize;i++){
			Node<K,V>* node=table[i];
			while(node!=nullptr){
				Node<K,V>* nextNode=node->next;
				int entry=hashCode(node->key);
				//头插法
				node->next=newTable[entry];
				newTable[entry]=node;
				node=nextNode;
			}
		}
		delete[] table;
		table=newTable;
	}

public:
	HashMap(){
		tableSize=16;
		elements=0;
		loadFactor=0.75;
		table=new Node<K,V>*[tableSize];
		for(int i=0;i<tableSize;i++){
			table[i]=nullptr;
		}
	}
	
	~HashMap(){
		//析构：释放所有节点和表
		for(int i=0;i<tableSize;i++){
			Node<K,V>* node=table[i];
			while(node!=nullptr){
				Node<K,V>* tmp=node;
				node=node->next;
				delete tmp;
			}
		}
		delete[] table;
	}
	
	void push(K key,V value){  //将关键字和对应数据放入哈希表
		if(elements>loadFactor*tableSize){
		resizeTable();
		}
		int entry=hashCode(key);
		Node<K,V>* node=new Node<K,V>(key,value);
		node->next=table[entry];
		table[entry]=node;
		elements++;
	}
	
	V get(K key){              //根据key找出对应的数据
		int entry=hashCode(key);
		Node<K,V>* node=table[entry];
		int hits=0;
		while(node!=nullptr){
			hits++;
			if(key==node->key){
				cout<<"hits after "<<hits<<" comparisons"<<endl;
				return node->value;
			}
			node=node->next;
		}
		throw "not found";	
	}
};

typedef struct{
	int sno;
	string sname;
	int score;
}Student;

int main()
{
	HashMap<int,Student> hashMap;
	for (int i=0;i<1500;++i){
        Student stu;
        stu.sno=i;
        stu.sname="Tom"+to_string(i);
        stu.score=i;
        hashMap.push(stu.sno,stu);
    }
	try{
		Student s=hashMap.get(121);
		cout<<"Sno:"<<s.sno<<"Sname:"<<s.sname<<"score:"<<s.score<<endl;
	}catch(const char* msg){
		cout<<msg<<endl;
	}
	return 0;
}