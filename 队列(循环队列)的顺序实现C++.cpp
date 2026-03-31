#include <iostream>

using namespace std;

class Queue{
private:
	int *arr;
	int rear;
	int front;
	int size;
	const int MAXSIZE=100;
	int count;
public:
	Queue(int size){
		this->size=size;
		arr=new int[size];
		rear=0;
		front=0;
		count=0;
	}
	
	~Queue(){
		if(arr!=NULL){
			delete arr;
			arr=NULL;
		}
	}
	
	bool isEmpty(){
		return rear==front;
	}
	
	bool isFull(){
		return (rear+1)%size==front;
	}
	
	void Enqueue(int x){
		if(isFull()){
			throw"Queue is full!\n";
		}
		rear=(rear+1)%size;  //队尾指针后移
		arr[rear]=x;
		count++;
		return;
	}
	
	void Deueue(){
		if(isEmpty()){
			throw"Queue is empty!\n";
		}
		front=(front+1)%size;  //更新队首指针
		count--;
		return;
	}
	
	int getFront(){
		if(isEmpty()){
			throw"Queue is empty!\n";
		}
		else{
			return arr[(front+1)%size];
		}
	}
};

int main()
{
	Queue q(10);  //构造函数传参,size==10
	for(int i=0;i<10;i++){
		q.Enqueue(i);
	}
	while(q.isEmpty()){
		cout<<q.getFront()<<endl;
	}
	return 0;
}