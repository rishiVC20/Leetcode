class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&a, vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=a.size() || j>=a[0].size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int up=0,right=0,down=0;
        if((i-1)>=0 && (j+1)<a[0].size() && a[i-1][j+1]>a[i][j])
            up=solve(i-1,j+1,a,dp)+1;
        if((j+1)<a[0].size() &&  a[i][j+1]>a[i][j])
            right=solve(i,j+1,a,dp)+1;
        if((i+1)<a.size() && (j+1)<a[0].size() && a[i+1][j+1]>a[i][j])
            down=solve(i+1,j+1,a,dp)+1;

        return (dp[i][j]=max(up,max(right,down)));                
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        int k=0;

        for(int i=0; i<n; i++){
            k=max(k,solve(i,0,grid,dp));
        }

        return k;
    }
};