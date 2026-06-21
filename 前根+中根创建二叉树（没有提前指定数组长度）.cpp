#include <iostream>
#define MAXSIZE 100

using namespace std;

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};

int findRoot(int in[],int start,int end,int rootVal)
{
	for(int i=start;i<=end;i++){
		if(rootVal=in[i]){
			return i;
		}
	}
	return -1;
}

TreeNode* createTree(int in[],int pre[],int start,int end,int &preIndex)
{
	if(start>end) return nullptr;
	int rootVal=pre[preIndex++];
	TreeNode* root=new TreeNode(rootVal);
	int pos=findRoot(in,start,end,rootVal);
	root->left=createTree(in,pre,start,pos-1,preIndex);
	root->right=createTree(in,pre,pos+1,end,preIndex);
	return root;
}

void preOrder(TreeNode* root,int res[],int &index)
{
	if(root!=nullptr){
		res[index++]=root->data;
		preOrder(root->left,res,index);
		preOrder(root->right,res,index);
	}
}

int main()
{
	int in[MAXSIZE];
	int pre[MAXSIZE];
	int inlen=0;
	while(cin>>in[inlen]){
		inlen++;
		if(cin.get()=='\n') break;
	}
	int prelen=0;
	while(cin>>pre[prelen]){
		prelen++;
		if(cin.get()=='\n') break;
	}
	int preIndex=0;
	TreeNode* root=createTree(in,pre,0,inlen-1,preIndex);
	int res[MAXSIZE];
	int index=0;
	preOrder(root,res,index);
	for(int i=0;i<index;i++){
		if(i>0) cout<<" ";
		cout<<res[i];
	}
	cout<<endl;
	return 0;
}