#include <iostream>
#include <string>
using namespace std;

struct TreeNode{
	char data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char val):data(val),left(nullptr),right(nullptr){}
};

int findPosition(string in,int start,int end,char val)
{
	for(int i=start;i<=end;i++){
		if(in[i]==val){
			return i;
		}
	}
	return -1;
}
TreeNode* buildTree(string pre,string in,int start,int end,int &preIndex)
{
	if(start>end) return nullptr;
	char rootVal=pre[preIndex++];
	//找到根节点再中序序列的位置
	TreeNode* T=new TreeNode(rootVal);
	int pos=findPosition(in,start,end,rootVal);
	T->left=buildTree(pre,in,start,pos-1,preIndex);
	T->right=buildTree(pre,in,pos+1,end,preIndex);
	return T;
}

void postOrder(TreeNode* T,string &result)
{
	if(T!=nullptr){
		postOrder(T->left,result);
		postOrder(T->right,result);
		result+=T->data;
	}
}

int main()
{
	string pre,in;
	cin>>pre>>in;
	//strlen不能用于string类型
	int len=in.length();
	int preIndex=0;
	TreeNode* T=buildTree(pre,in,0,len-1,preIndex);
	string result;
	postOrder(T,result);
	cout<<result<<endl;
	return 0;
}