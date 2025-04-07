class Solution {
public:
    bool solve(int ind, int cs, int tar, vector<int> &nums, vector<vector<int>> &dp){
        if(cs==tar){
            return true;
        }
        if(ind==nums.size() || cs>tar){
            return false;
        }
        if(dp[ind][cs] != -1){
            return dp[ind][cs];
        }

        bool f1=solve(ind+1,cs+nums[ind],tar,nums,dp);
        bool f2=solve(ind+1,cs,tar,nums,dp);

        return dp[ind][cs] = f1 || f2;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1){
            return false;
        }
        int tar=sum/2;

        vector<vector<int>>dp(n+1,vector<int>(tar+1,-1));
        return solve(0,0,tar,nums,dp);
    }
};