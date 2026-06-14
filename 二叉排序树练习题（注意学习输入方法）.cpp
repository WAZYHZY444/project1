/*
给定T组测试数据，每组包含两个整数序列。分别将每个序列按顺序插入初始为空的二义搜索树（BST)，插入时若当前值已存在于例中则讲过（不重复插人），奇判新每销中的两棵二叉
搜索树是否完全相同（即树的结构相间，且对应节点的值相等）。

输入：
第一行 个整数T(1≤T≤100)，表示测试组数。
接下来每组数据格式如下：
1.第一行一个整数n(T≤n≤1000)，表示序列的长度。
2.第二行包含n个整数，为第一个序列。
3.第三行包含n个整数，为第二个序列。
  所有整数的绝对值不超过16^9。
  
输出：
对于每组数据，输出一行YES 或 NO，表示该组两棵二叉提索树是否相同。
*/


//-------注意两种不同的输出-------------------//
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};

TreeNode* insert(TreeNode* root,int val)
{
	if(root==nullptr){
		root=new TreeNode(val);
	}
	if(root->data==val){
		return root;
	}
	else if(val>root->data){
		root->right=insert(root->right,val);
	}
	else{
		root->left=insert(root->left,val);
	}
	return root;
}

TreeNode* createTree(int a[],int n){
	TreeNode* root=nullptr;
	for(int i=0;i<n;i++){
		root=insert(root,a[i]);
	}
	return root;
}

bool isSame(TreeNode* tree1,TreeNode* tree2)
{
	if(tree1==nullptr&&tree2==nullptr) return true;
	if(tree1==nullptr||tree2==nullptr) return false;
	if(tree1->data!=tree2->data) return false;
	return isSame(tree1->left,tree2->left)&&isSame(tree1->right,tree2->right);
}

/*
int main()
{
	int T;  //测试组数
	cin>>T;	
	while(T--){
		int n;  //序列长度
		cin>>n;
		
		//读入第一棵树的插入序列
		vector<int> tree1(n);
		for(int i=0;i<n;i++){
			cin>>tree1[i];
		}
		
		//读入第二棵树的插入序列
		vector<int> tree2(n);
		for(int i=0;i<n;i++){
			cin>>tree2[i];
		}
		
		//tree1.data() C++17以后的写法---->&tree1[0]可以改为传地址
		TreeNode* root1=createTree(tree1.data(),n);  //注意：如果这里直接写tree1，那传入的是数据类型是vector<int>，与函数列表不匹配
		TreeNode* root2=createTree(tree2.data(),n);
		if(isSame(root1,root2))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
*/

int main()
{
	int T;  //测试组数
	cin>>T;
	vector<string> res;  //存储每组的结果YES\NO
	while(T--){
		int n;  //序列长度
		cin>>n;
		
		//读入第一棵树的插入序列
		vector<int> tree1(n);
		for(int i=0;i<n;i++){
			cin>>tree1[i];
		}
		
		//读入第二棵树的插入序列
		vector<int> tree2(n);
		for(int i=0;i<n;i++){
			cin>>tree2[i];
		}
		
		//tree1.data() C++17以后的写法---->&tree1[0]可以改为传地址
		TreeNode* root1=createTree(&tree1[0],n);  //注意：如果这里直接写tree1，那传入的是数据类型是vector<int>，与函数列表不匹配
		TreeNode* root2=createTree(&tree2[0],n);
		if(isSame(root1,root2))
			res.push_back("YES");
		else
			res.push_back("NO");
	}
	for(string s:res){
		cout<<s<<endl;
	}
	return 0;
}
//学习笔记：cin会自动跳过空格、换行、制表符等空白符，不需要手动处理换行