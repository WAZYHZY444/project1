#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct TreeNode{
	char data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};

int findRoot(int start,int end,string in,char key)
{
	for(int i=start;i<=end;i++){
		if(in[i]==key){
			return i;
		}
	}
	return -1;
}

TreeNode* createTree(string in,string post,int start,int end,int &postIndex,int lenIn)
{
	if(start>end) return nullptr;
	char rootVal=post[postIndex--];
	TreeNode* root=new TreeNode(rootVal);
	int pos=findRoot(start,end,in,rootVal);
	root->right=createTree(in,post,pos+1,end,postIndex,lenIn);
	root->left=createTree(in,post,start,pos-1,postIndex,lenIn);
	return root;
}

int maxWidth(TreeNode* root)
{
	if(root==nullptr) return 0;
	queue<TreeNode*> q;
	q.push(root);
	int max_width=0;
	while(!q.empty()){
		int level_size=q.size();
		max_width=max(max_width,level_size);
		
		for(int i=0;i<level_size;i++){
			TreeNode* cur=q.front();
			q.pop();
			
			if(cur->left!=nullptr){
				q.push(cur->left);
			}
			if(cur->right!=nullptr){
				q.push(cur->right);
			}
		}
	}
	return max_width;
}

void inOrder(TreeNode* root)
{
	if(root!=nullptr){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

int main()
{
	string in,post;
	cin>>in>>post;
	int lenIn=in.size();
	int postIndex=lenIn-1;
	TreeNode* root=createTree(in,post,0,lenIn-1,postIndex,lenIn);
	inOrder(root);
	cout<<endl;
	
	int width=maxWidth(root);
	cout<<width<<endl;
	return 0;
}