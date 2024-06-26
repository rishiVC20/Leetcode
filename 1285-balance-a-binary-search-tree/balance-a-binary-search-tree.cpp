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
    void inorder(TreeNode* &root, vector<int> &arr){
        if (root==NULL) 
            return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* updateTree(vector<int> &arr, int st, int end)
    {
        if (st>end)
            return NULL;

        int mid = (st+end)/2;
        TreeNode* newTree = new TreeNode(arr[mid]);
        newTree->left = updateTree(arr,st,mid-1);
        newTree->right = updateTree(arr,mid+1,end);  

        return newTree;  
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        int n = arr.size();
        

        return updateTree(arr,0,n-1);;
    }
};