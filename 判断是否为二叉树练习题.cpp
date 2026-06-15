#include <iostream>
#include <string>

using namespace std;

struct TreeNode{
	char data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char val):data(val),left(nullptr),right(nullptr){}
};

int i=0;
void createTree(TreeNode* &root,string str)
{
	char ch=str[i++];
	if(ch=='#') root=nullptr;
	else{
		root=new TreeNode(ch);
		createTree(root->left,str);
		createTree(root->right,str);
	}
}

int calHeight(TreeNode* root)
{
	if(root==nullptr) return 0;
	int h1=calHeight(root->left);
	int h2=calHeight(root->right);
	return h1>h2?h1+1:h2+1;
}

bool isBBT(TreeNode* root)
{
	if(root==nullptr) return true;
	int h1=calHeight(root->left);
	int h2=calHeight(root->right);
	if(abs(h1-h2)>1) return false;
	return isBBT(root->left)&&isBBT(root->right);
}

int main()
{
	string str;
	cin>>str;
	TreeNode* root;
	createTree(root,str);
	if(isBBT(root)) cout<<"is AVL tree"<<endl;
	else cout<<"is not AVL tree"<<endl;
	return 0;
}
