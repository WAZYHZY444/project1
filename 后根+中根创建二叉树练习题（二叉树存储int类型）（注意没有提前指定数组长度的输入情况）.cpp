#include <iostream>
#define MAXSIZE 100
using namespace std;

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};

int findRootIn(int start,int end,int rootVal,int in[])
{
	for(int i=start;i<=end;i++){
		if(in[i]==rootVal){
			return i;
		}
	}
	return -1;
}

TreeNode* createTree(int in[],int post[],int start,int end,int &poIndex)
{
	if(start>end) return nullptr;  //递归结束条件
	int rootVal=post[poIndex--];
	TreeNode* root=new TreeNode(rootVal);
	int pos=findRootIn(start,end,rootVal,in);
	root->right=createTree(in,post,pos+1,end,poIndex);
	root->left=createTree(in,post,start,pos-1,poIndex);
	return root;
}

void preOrder(TreeNode* root,int res[],int &idx)
{
	if(root!=nullptr){
//		cout<<root->data<<' ';  //末尾会有空格
		res[idx++]=root->data;
		preOrder(root->left,res,idx);
		preOrder(root->right,res,idx);
	}
}

int main()
{
	int in[MAXSIZE];
	int post[MAXSIZE];
	int inlen=0;
	//读取第一行：中序序列
	while(cin>>in[inlen]){
		inlen++;
		if(cin.get()=='\n') break;
	}
	//读取第二行：后序序列
	int postlen=0;
	while(cin>>post[postlen]){
		postlen++;
		if(cin.get()=='\n') break;
	}
	
	int poIndex=inlen-1;
	TreeNode* root=createTree(in,post,0,inlen-1,poIndex);
	
	//存储前序结果
	int preRes[MAXSIZE];
	int preIndex=0;
	preOrder(root,preRes,preIndex);
	for(int i=0;i<preIndex;i++){
		if(i>0) cout<<" ";
		cout<<preRes[i];
	}
	cout<<endl;
	
	return 0;
}