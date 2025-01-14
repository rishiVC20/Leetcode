class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        
        int n=coins.size();
        int m=coins[0].size();
        int k=2;

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3)));

        dp[n-1][m-1][0]=coins[n-1][m-1];
        dp[n-1][m-1][1]=max(0,coins[n-1][m-1]);
        dp[n-1][m-1][2]=max(0,coins[n-1][m-1]);
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1)
                    continue;
                for(int k=0; k<=2; k++){
                    if(k==0){
                        int m1=INT_MIN,m2=INT_MIN;
                        if(i+1<n){
                            m1=dp[i+1][j][k];
                        }
                        if(j+1<m){
                            m2=dp[i][j+1][k];
                        }
                        dp[i][j][k]=coins[i][j] + max(m1,m2);
                        continue;
                    }

                    if(coins[i][j] >= 0){
                        int m1=INT_MIN,m2=INT_MIN;
                        if(i+1<n){
                            m1=dp[i+1][j][k];
                        }
                        if(j+1<m){
                            m2=dp[i][j+1][k];
                        }
                        dp[i][j][k] = coins[i][j]+max(m1,m2);
                    }
                    else{
                        int m1=INT_MIN,m2=INT_MIN,m3=INT_MIN,m4=INT_MIN;
                        if(i+1 < n){
                            m1=dp[i+1][j][k-1];
                            m3=dp[i+1][j][k];
                        }
                        if(j+1 < m){
                            m2=dp[i][j+1][k-1];
                            m4=dp[i][j+1][k];
                        }
                        int k1=max(m1,m2);
                        int k2=coins[i][j]+max(m3,m4);
                        // dp[i][j][k] = max(dp[i+1][j][k-1],dp[i][j+1][k-1]);
                        dp[i][j][k]=max(k1,k2);
                    }
                }
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++)
        //         cout<<dp[i][j][0]<<' ';
        //     cout<<endl;    
        // }
        // cout<<endl;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++)
        //         cout<<dp[i][j][1]<<' ';
        //     cout<<endl;    
        // }
        // cout<<endl;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++)
        //         cout<<dp[i][j][2]<<' ';
        //     cout<<endl;    
        // }
        return dp[0][0][2];
    }
};