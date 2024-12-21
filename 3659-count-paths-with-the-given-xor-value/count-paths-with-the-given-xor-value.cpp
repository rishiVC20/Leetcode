class Solution {
    #define ll long long
    const int mod=1e9+7;
public:
    int solve(int i, int j, vector<vector<int>> &grid, int k, ll &ans, int v, vector<vector<vector<int>>> &dp){
        if(i<0 || j<0 )
            return 0;
        
        // int p=v;
        v=v^grid[i][j];
        if(i==0 && j==0){
            if(v==k)
                return 1;
            // ans=ans%mod;
            return 0;
        }
        if(dp[i][j][v]!=-1)
            return dp[i][j][v];
        int x=solve(i-1,j,grid,k,ans,v,dp)%mod;
        int y=solve(i,j-1,grid,k,ans,v,dp)%mod;
        // return dp[i][j]=(x+y)%mod;
        return dp[i][j][v]=(x+y)%mod;
        // v=p;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        // vector<ll>ans;
        ll ans=0;

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(20,-1)));
        return solve(n-1,m-1,grid,k,ans,0,dp);

        // int mod=1e9+7;

        // int b=(ll)ans%mod;

        // return ans;
    }
};

// class Solution {
//     #define ll long long
//     const int mod=1e9+7;
// public:
//     ll solve(int i, int j, vector<vector<int>> &grid, int k, ll &ans, int v,vector<vector<int>> &dp){
//         if(i<0 || j<0 )
//             return 0;

//         // int p=v;
//         // v=v^grid[i][j];
//         if(dp[i][j] != -1)
//             return dp[i][j];
//         if(i==0 && j==0){
//             // if(v==k){
//             //     if(dp[i][j]==-1)
//             //         dp[i][j]=0;
//             //     dp[i][j]++;
//             // }
//             // v=p;
//             // return dp[i][j]%mod;
//             return dp[i][j]= (v^grid[i][j]==k) ? 1:0;
//             // return;
//         }
        
        
//         int x=solve(i-1,j,grid,k,ans,v^grid[i][j],dp);
//         int y=solve(i,j-1,grid,k,ans,v^grid[i][j],dp);
        
//         // v=p;
//         return dp[i][j]=(x+y)%mod;
//     }
//     int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
//         // vector<ll>ans;
//         ll ans=0;

//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(n-1,m-1,grid,k,ans,0,dp);

//         // int mod=1e9+7;

//         // int b=(ll)ans%mod;

//         // return ans;
//     }
// };