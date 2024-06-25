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
    void inorder(TreeNode* &root, vector<int>&ans){
        if (root == NULL)
            return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);    
    }
    void sum(vector<int> &ans, int n){
        for (int i = n-2; i>=0; i--){
            ans[i] +=ans[i+1];
        }
    }
    
    void updateBST(TreeNode* &root, vector<int> &ans, int &index){
        if (root == NULL)
            return;

        updateBST(root->left,ans,index);
        root->val = ans[index++];
        updateBST(root->right, ans,index);
        // return root;    
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        int index = 0;
        int n = ans.size();
        sum(ans,n);
        updateBST(root,ans,index);
        return root;
    }
};