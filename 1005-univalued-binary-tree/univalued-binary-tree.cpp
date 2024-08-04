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
    void inorder(TreeNode* root, vector<int> &arr){
        if (root==NULL)
            return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);    
    }
    bool isUnivalTree(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        set<int>st;
        for (auto i:arr)
            st.insert(i);
        for (auto i:arr)
            cout<<i<<' ';    
        return st.size()==1;    
    }
};