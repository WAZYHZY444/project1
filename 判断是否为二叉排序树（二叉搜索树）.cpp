#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};

int i=0;
void buildTree(TreeNode* &root,string s)
{
	int num=0;
	while(s[i]==','||s[i]==' ') i++;
	
	if(s[i]=='#'){
		root=nullptr;
		i++;
	}else{
		while(s[i]>='0'&&s[i]<='9'){
			num=num*10+(s[i]-'0');
			i++;
		}
		root=new TreeNode(num);
		buildTree(root->left,s);
		buildTree(root->right,s);
	}
}

void inOrder(TreeNode* root,vector<int> &res)
{
    if(root==nullptr) return;
    inOrder(root->left,res);
    res.push_back(root->data);
    inOrder(root->right,res);
}

bool isValidBST(TreeNode* root)
{
    vector<int> res;
    inOrder(root,res);
    for(int i=0;i<res.size()-1;i++){
        if(res[i]>=res[i+1]){
            return false;
        }
    }
    return true;
}


int main()
{
	i=0;
	
	string str;
	cin>>str;
//	getline(cin, str);  // 读取整行，包括空格
	TreeNode* root;
	buildTree(root,str);
	bool res=isValidBST(root);
	if(res)
		cout<<"是二叉排序树"<<endl;
	else
		cout<<"不是二叉排序树"<<endl;
	
	return 0; 
}