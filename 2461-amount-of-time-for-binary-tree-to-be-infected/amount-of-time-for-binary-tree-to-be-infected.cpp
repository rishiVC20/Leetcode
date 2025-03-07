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
    void mapParent(map<TreeNode*,TreeNode*>&mp1, TreeNode* root){
        if(root==NULL)
            return;
        if(root->left){
            mp1[root->left]=root;
        }    
        if(root->right){
            mp1[root->right]=root;
        }
        mapParent(mp1,root->left);
        mapParent(mp1,root->right);
    }
    void findTarget(TreeNode* root, int target, TreeNode* &temp){
        if(root==NULL)
            return;
        
        if(root->val==target){
            temp=root;
            return;
        }    
        findTarget(root->left,target,temp);
        findTarget(root->right,target,temp);
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>m1;
        TreeNode* newnode=new TreeNode(-1);
        m1[root]=newnode;
        mapParent(m1,root);
        queue<TreeNode*>q;
        int jp=0;
        TreeNode* temp;
        findTarget(root,start,temp);
        q.push(temp);
        map<TreeNode*,bool>mp2;
        mp2[temp]=true;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0; i<sz; i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL && mp2.find(node->left)==mp2.end()){
                    q.push(node->left);
                    mp2[node->left]=true;
                }
                if(node->right!=NULL && mp2.find(node->right)==mp2.end()){
                    q.push(node->right);
                    mp2[node->right]=true;
                }
                TreeNode* par=m1[node];
                if(par->val!=-1 && mp2.find(par)==mp2.end()){
                    q.push(par);
                    mp2[par]=true;
                }
            }
            if(!q.empty()){
                jp++;
            }
            
        }
        
        return jp;
    }
};