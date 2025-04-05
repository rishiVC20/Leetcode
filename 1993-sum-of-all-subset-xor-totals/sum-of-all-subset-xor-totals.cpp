class Solution {
public:
    void solve(int ind, vector<int> &nums, vector<int> &a, vector<vector<int>> &v){
        if(ind==nums.size()){
            if(a.size()>0){
                v.push_back(a);
            }
            return ;
        }

        a.push_back(nums[ind]);
        solve(ind+1,nums,a,v);
        a.pop_back();
        solve(ind+1,nums,a,v);
        
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<vector<int>>pk;
        vector<int>sp;
        solve(0,nums,sp,pk);
        for(auto it:pk){
            int cn=0;
            for(auto j:it){
                cn=cn^j;
            }
            ans+=cn;
        }

        return ans;
    }
};