#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};

int i=0;
void createTree(string str,TreeNode* &root)
{
	if(str[i]=='#'){
		root=nullptr;
		i++;
	}
	while(str[i]==',') i++;
	if(isdigit(str[i])){
		int num=0;
		while(isdigit(str[i])){
			num=num*10+(str[i]-'0');
			i++;
		}
		root=new TreeNode(num);
		createTree(str,root->left);
		createTree(str,root->right);
	}	
}

//从下到上层序遍历
void divLeverOrder(TreeNode* root)
{
	if(root==nullptr) return;
	
	queue<TreeNode*> q;
	stack<TreeNode*> s;
	
	q.push(root);
	s.push(root);
	
	while(!q.empty()){
		TreeNode* p=q.front();
		q.pop();
		//每层输出是从左到右
		if(p->right!=nullptr){
			q.push(p->right);
			s.push(p->right);
		}
		if(p->left!=nullptr){
			q.push(p->left);
			s.push(p->left);
		}
	}
	
	while(!s.empty()){
		TreeNode* temp=s.top();
		cout<<temp->data<<" ";
		s.pop();
	}
	cout<<endl;
}

//从上到下层序遍历
void leverOrder(TreeNode* root)
{
	queue<TreeNode*> Q;
	Q.push(root);
	while(!Q.empty()){
		TreeNode* p=Q.front();
		cout<<p->data<<" ";
		Q.pop();
		
		//左节点入队
		if(p->left!=nullptr){
			Q.push(p->left);
		}
		//右节点入队
		if(p->right!=nullptr){
			Q.push(p->right);
		}
	}
	cout<<endl;
}

int main()
{
	string str;
	i=0;
	cin>>str;
	
	TreeNode* root;
	createTree(str,root);
	divLeverOrder(root);
	leverOrder(root);
	return 0;
}