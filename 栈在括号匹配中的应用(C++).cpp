#include <iostream>
#include <string>
using namespace std;

template<class T>
class Stack{
private:
	T* data; // 动态数组：存数据
	int top; // 栈顶指针（下标）
	int maxSize; // 栈最大容量
public:
	Stack(int size);
	~Stack();
	bool isEmpty();
	bool isFull();
	bool push(T value);
	bool pop();
	T getTop();
};

template<class T>
Stack<T>::Stack(int size) {
	maxSize = size; // 设置容量
	data = new T[size]; // 开辟数组
	top = -1; // 空栈
}

template<class T>
Stack<T>::~Stack() {
	delete[] data;
}

template<class T>
bool Stack<T>::isFull() {
	return top == maxSize - 1;
}

template<class T>
bool Stack<T>::isEmpty() {
	return top == -1;
}

template<class T>
bool Stack<T>::push(T value) {
	if (isFull()) {
	cout << "栈满，无法入栈！" << endl;
	return false;
	}
	data[++top] = value;
	return true;
}

template<class T>
bool Stack<T>::pop() {
	if (isEmpty()) {
	cout << "栈空，无法出栈！" << endl;
	return false;
	}
	top--;
	return true;
}

template<class T>
T Stack<T>::getTop() {
	if (isEmpty()) {
	cout << "栈为空！" << endl;
	return -1;
	}
	return data[top];
}

bool bracketCheck(string str,int len)
{
	Stack<char>S(len);
	for(int i=0;i<len;i++){
		if(str[i]=='('||str[i]=='{'||str[i]=='['){
			if(!S.push(str[i])){  //检查站是否已满
				return false;
			}
		}
		else if(str[i]==')'||str[i]=='}'||str[i]==']'){
			if(S.isEmpty())
				return false;
			char topelem;
			topelem=S.getTop();
			S.pop();
			if(str[i]==')'&&topelem!='(')
				return false;
			if(str[i]=='}'&&topelem!='{')
				return false;
			if(str[i]==']'&&topelem!='[')
				return false;
		}
	}
	return S.isEmpty();  //最后还要验证栈空，确保所有的都配对了
}
int main()
{
	string str;
	getline(cin,str);
	int len=str.length();
	bool x=bracketCheck(str,len);
	if(!x){
		cout<<"匹配失败！"<<endl;
	}else{
		cout<<"匹配成功！"<<endl;
	}
	return 0;
}