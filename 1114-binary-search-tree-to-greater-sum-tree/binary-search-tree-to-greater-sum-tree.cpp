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
    void inorder(vector<int> &arr, TreeNode* &root){
        if (root == NULL)
            return;

        inorder(arr,root->left);
        arr.push_back(root->val);
        inorder(arr,root->right);    
    }
    void sum(vector<int> &arr, int n){
        for (int i=n-2; i>=0; i--){
            arr[i] += arr[i+1];
        }
    }
    void updateTree(vector<int> &arr, int &index, TreeNode* &root){
        if (root == NULL)   
            return;
        updateTree(arr,index,root->left);
        root->val = arr[index++];
        updateTree(arr,index,root->right);    
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>arr;
        inorder(arr,root);
        for (auto i:arr)
            cout<<i<<' ';
        cout<<endl;    
        int n = arr.size();
        sum (arr,n);
        for (auto i:arr)
            cout<<i<<' ';
        int index = 0;
        updateTree(arr,index,root);

        return root;
    }
};