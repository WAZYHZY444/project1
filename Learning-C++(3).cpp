//C++编程思想：一是面向对象思想，二是泛型编程。泛型编程只要利用的技术就是模板
//模板机制：函数模板和类模板

//函数模板
template<typename T>
void Swap(T &a,T &b){
	T temp=a;
	a=b;
	b=temp;
}