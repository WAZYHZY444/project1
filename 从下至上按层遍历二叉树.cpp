#include <iostream>
#include <string>
using namespace std;

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};

//创建二叉树
int i=0;
void createTree(TreeNode* &T,string s)
{
	int num=0;
	if(s[i]=='#'){
		T=nullptr;
		i++;
	}else{
		while(s[i]>='0'&&s[i]<='9'){
			num=num*10+(s[i]-'0');
		}
		T=new TreeNode(num);
		createTree(T->left,s);
		createTree(T->right,s);
	}
}

int main()
{
	i=0;
	string s;
	cin s;
	TreeNode* T;
	createTree(T,s);
	
	return 0;
}