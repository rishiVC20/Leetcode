class Solution {
public:
    int solve(int col, int row, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        int n=triangle.size();
        if(row==n){
            return 0;
        }

        if(dp[row][col] != -1)
            return dp[row][col];

        int m1=triangle[row][col]+solve(col,row+1,triangle,dp);
        int m2=triangle[row][col]+solve(col+1,row+1,triangle,dp);

        return dp[row][col]=min(m1,m2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,triangle,dp);      
    }
};