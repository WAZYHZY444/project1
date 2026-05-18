#include <iostream>
#include <string>
using namespace std;

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	//初始化列表
	TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};

int getLeftLeafValue(TreeNode* T)
{
	if(T==nullptr) return 0;
	if(T->left==nullptr) return 0;
	if(T->left->left==nullptr&&T->left->right==nullptr){
		return T->left->data;
	}
	return 0;
}

//前序计算左叶节点之和
int sumLeftLeaf(TreeNode* T)
{
	if(T==nullptr) return 0;
	return getLeftLeafValue(T)+sumLeftLeaf(T->left)+sumLeftLeaf(T->right);
}

//创建二叉树
int i=0;
void buildTree(TreeNode* &T,string s)
{
	int num=0;
	while(s[i]==','||s[i]==' ') i++;
	
	if(s[i]=='#'){
		T=nullptr;
		i++;
	}else{
		while(s[i]>='0'&&s[i]<='9'){
			num=num*10+(s[i]-'0');
			i++;
		}
		T=new TreeNode(num);
		buildTree(T->left,s);
		buildTree(T->right,s);
	}
}

int main()
{
	i=0;
	string s;
	cin>>s;
	TreeNode* T;
	buildTree(T,s);
	int result=sumLeftLeaf(T);
	cout<<result;
	return 0;
}