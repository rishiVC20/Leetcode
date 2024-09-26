class Solution {
public:
    bool solve(vector<int>&nums, int k, int n,vector<int>&dp){
        if(k==n-1)
            return true;

        if(nums[k]==0)
            return false;
        if(dp[k]!=-1)
            return dp[k];
        for(int i=k+1; i<=nums[k]+k; i++){
            bool ans=solve(nums,i,n,dp);
            if(i<n && ans){
                dp[i]=1;
                return true;
            }
        }        
        dp[k]=0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,0,n,dp);
    }
};