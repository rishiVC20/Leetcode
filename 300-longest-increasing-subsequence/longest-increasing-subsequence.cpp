class Solution {
public:
    int solve(vector<int> &a, int i, vector<int> &dp){
        if(i==0)
            return 1;

        if(dp[i] != -1)
            return dp[i];
        int mx=1;
        for(int j=0; j<i; j++){
            if(a[j] < a[i]){
                mx=max(mx,1+solve(a,j,dp));
            }
        }    

        return dp[i]=mx; 
    }
    int lengthOfLIS(vector<int>& nums) {
        int maxi=1;
        int n=nums.size();
        vector<int>dp(n+1,-1);
        for(int i=0; i<n; i++){
            maxi=max(maxi,solve(nums,i,dp));
        }

        return maxi;
    }
};