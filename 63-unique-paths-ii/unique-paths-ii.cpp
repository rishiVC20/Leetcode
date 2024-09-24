class Solution {
public:
    int solve(int r, int c, vector<vector<int>>&v, vector<vector<int>>&dp){
        if(r<0 || c<0 || v[r][c]==1)
            return 0;
        if(r==0 && c==0)
            return 1;

        if(dp[r][c]!=-1)
            return dp[r][c];   

        int left=solve(r,c-1,v,dp);
        int up=solve(r-1,c,v,dp);

        return dp[r][c]=left+up;        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(n-1,m-1,obstacleGrid,dp);
    }
};