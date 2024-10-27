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
    int calHeight(TreeNode* root){
        if(root==NULL)
            return 0;

        int left=calHeight(root->left);
        int right=calHeight(root->right);

        return max(left,right)+1;    
    }
    vector<vector<string>> printTree(TreeNode* root) {
        
        queue<pair<int,TreeNode*>>q;
        
        int height=calHeight(root);
        height--;
        cout<<height<<' ';
        int n=pow(2,height+1)-1;
        vector<vector<string>>v(height+1,vector<string>(n,""));
        int j=0;
        int g=(n-1)/2;
        v[j][g]=to_string(root->val);
        q.push({g,root});
        while(!q.empty()){
            j++;
            if(j==v.size())
                break;
            int sz=q.size();
            for(int i=0; i<sz; i++){
                auto t=q.front();
                q.pop();
                int p1=t.first;
                TreeNode* p2=t.second;
                int c1=p1-pow(2,height-(j-1)-1);
                int c2=p1+pow(2,height-(j-1)-1);
                if(p2->left){
                    q.push({c1,p2->left});
                    v[j][c1]=to_string(p2->left->val);
                }
                if(p2->right){
                    q.push({c2,p2->right});
                    v[j][c2]=to_string(p2->right->val);
                }    
            }
        }

        return v;
    }
};