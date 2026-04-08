 #include <iostream>
#include <string>

using namespace std;

struct Info{
	int sno;
	string sname;
	float score;
};
struct Student{
	Info* data;
	Student* next;
};

class LinkList{
private:
	Student* head; //头指针
public:
	LinkList(){
		head=NULL;
	}
	~LinkList(){   //释放链表
		Student* temp;
		while(head!=NULL){
			temp=head;
			head=head->next;
			delete temp->data;  //释放Info对象
			delete temp;
		}
	}
	
	//头插法插入节点
	void Add(Info* info){
		Student* newnode=new Student;
		newnode->data=info;
		newnode->next=head;
		head=newnode;
	}
	
	//按学号升序插入节点
	void Insert(Info* info){
		Student* newnode=new Student;
		newnode->data=info;
		newnode->next=NULL;
		//空链表或插入到头部
		if(head==NULL||head->data->sno>info->sno){
			newnode->next=head;
			head=newnode;
			return;
		}
		//找到插入位置
		Student* p=head;
		while(p->next!=NULL&&p->next->data->sno<info->sno){
			p=p->next;
		}
		newnode->next=p->next;
		p->next=newnode;
	}
	
	//删除节点(只能删除一个节点，即要删除的节点只有一个)
	void Delete(int sno){
		if(head==NULL){ //链表为空
			return;
		}
		Student* p=head;
		Student* prev=NULL;
		while(p!=NULL&&p->data->sno!=sno){
			prev=p;
			p=p->next;
		}
		if(p==NULL){
			cout<<"要找的信息没找到"<<endl;
			return;
		}
		if(prev==NULL){  //第一个节点就是要找的
			head=p->next;  //将头节点移动到第一个节点的后面
		}
		else{
			prev->next=p->next;
		}
		delete p->data;
		delete p;  //释放指向删除节点的指针
		cout<<"学号为"<<sno<<"已删除"<<endl;
	}
	
	//打印链表
	void Display(){
		if(head==NULL){
			return;
		}
		Student* p=head;
		while(p!=NULL){
			cout<<"学号:"<<p->data->sno<<"   姓名:"<<p->data->sname<<"   成绩:"<<p->data->score<<endl;
			
			p=p->next;
		}
	}
	
	//按学号查找学生
	void Search(int sno){
		if(head==NULL){
			return;
		}
		Student* p=head;
		while(p!=NULL){
			if(p->data->sno==sno){
				cout<<"查找结果："<<endl;
				cout<<"学号:"<<p->data->sno<<"   姓名:"<<p->data->sname<<"   成绩:"<<p->data->score<<endl;
				return;
			}
			p=p->next;	
		}
		cout<<"该学号的学生不存在"<<endl;
	}
};


int main()
{
	LinkList list;
	
	Info* stu1=new Info{101,"ZhangSan",98.5};
	Info* stu2=new Info{102,"LiSi",89.0};
	Info* stu3=new Info{103,"WangWu",84.5};
	Info* stu4=new Info{104,"ShaDan",87.5};
	Info* stu5=new Info{105,"ErSha",88.5};
	
	list.Insert(stu1);
	list.Insert(stu2);
	list.Insert(stu4);
	
	cout<<"--------打印学生信息----------"<<endl;
	list.Display();
	cout<<"--------查找102号学生信息----------"<<endl;
	list.Search(102);
	cout<<"--------删除101号学生信息----------"<<endl;
	list.Delete(101);
	list.Display();
	cout<<"-----按学号升序插入103号学生信息------"<<endl;
	list.Insert(stu3);
	list.Display();
	cout<<"--------插入105号学生信息(表头)----------"<<endl;
	list.Add(stu5);
	list.Display();
	
	return 0;	
}