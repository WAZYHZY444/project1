#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN=100;

struct Item{
	int w;  //重量
	int p;  //价值
	bool operator < (const Item& other) const{
		return (double)p/w > (double)other.p/other.w;
	}
}items[MAXN];

//活结点结构体
struct Node{
	int up;  //上界
	int cp;  //背包当前价值
	int cw;  //背包当前重量
	bool lchild;  //是否为左孩子（true代表选择该物品，false代表不选）
	int level;  //当前所在层数
	bool operator < (const Node& other)const{
		return up<other.up;  //上界up越大越优先
	}
};

//优先队列
priority_queue<Node> pq;

int n;  //物品总数
int c;  //背包总重量
int bestp=0;

//计算上界
int Bound(int i,int cw,int cp)
{
	int cleft=c-cw;  //剩余容量
	int b=cp;  //背包已有价值
	
	while(i<=n&&items[i].w<=cleft){
		cleft-=items[i].w;
		b+=items[i].p;
		i++;
	}
	if(i<=n){
		b+=items[i].p/items[i].w*cleft;
	}
	return b;
}

//添加活结点到优先队列
void addLiveNode(int up,int cp,int cw,bool ch,int level)
{
	Node node;
	node.up=up;
	node.cp=cp;
	node.cw=cw;
	node.lchild=ch;
	node.level=level;
	pq.push(node);
}

void MaxKnapsack()
{
	int i=1;  //从第1个物品开始
	int cp=0,cw=0;
	int up=Bound(1,cw,cp);  //初始上界
	while(i!=n+1){
		//检查当前节点的左儿子节点
		int wt=cw+items[i].w;
		if(wt<=c){
			if(cp+items[i].p>bestp) bestp=cp+items[i].p;
			addLiveNode(up,cp+items[i].p,cw+items[i].w,true,i+1);
		}
		
		up=Bound(i+1,cw,cp);  //因为检查右儿子节点是不选当前物品的，所以cw和cp就不需要更新
		//检查当前节点的左儿子节点
		if(up>=bestp){  //右子树可能含有最优解
			addLiveNode(up,cp,cw,false,i+1);
		}
		
		//去下一个扩展结点
		if(pq.empty()) break;  //防止空队列报错
		Node nextNode=pq.top();
		pq.pop();   //优先级最高的出队
		
		//更新当前扩展节点的状态
		up=nextNode.up;
		cp=nextNode.cp;
		cw=nextNode.cw;
		i=nextNode.level;
	}
}

int main()
{
	n=4;
	c=10;
	items[1]={2,6};
	items[2]={3,5};
	items[3]={4,6};
	items[4]={5,8};
	//按单位价值排序
	sort(items+1,items+n+1);
	MaxKnapsack();
	cout<<"最优价值为："<<bestp<<endl;
	return 0;
}