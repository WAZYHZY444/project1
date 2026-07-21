/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countDominantNodes(TreeNode* root) {
        int count=0;
        int res=func(root,count);
        return count;
    }

    int func(TreeNode* root,int &count){
        if(root==nullptr) return -1;
        int maxVal=max(root->val,max(func(root->left,count),func(root->right,count)));
        if(root->val==maxVal) count++;
        return maxVal;
    }
};