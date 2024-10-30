class Solution {
public:
    int solve1(int i, vector<int>&a, vector<int>&dp){
        if(i==0)
            return 1;

        if(dp[i] != -1)
            return dp[i];

        int maxi=1;
        for(int j=0; j<i; j++){
            if(a[j] < a[i]){
                maxi=max(maxi,1+solve1(j,a,dp));
            }
        }    

        return dp[i]=maxi;
    }
    int solve2(int i, vector<int>&a, vector<int>&dp){
        if(i==a.size()-1)
            return 1;

        if(dp[i] != -1)
            return dp[i];    

        int maxi=1;
        for(int j=i+1; j<a.size(); j++){
            if(a[j] < a[i]){
                maxi=max(maxi,1+solve2(j,a,dp));
            }
        }    

        return dp[i] = maxi;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        vector<int>a(n,1);
        for(int i=0; i<n; i++){
            a[i]=solve1(i,nums,dp1);
        }
        vector<int>b(n,1);
        for(int i=n-1; i>=0; i--){
            b[i] = solve2(i,nums,dp2);
        }

        int mn=0;
        // for(auto i:a)
        //     cout<<i<<' ';
        // cout<<endl;
        // for(auto i:b)
            // cout<<i<<' ';    
        for(int i=0; i<n; i++){
            int p=a[i],q=b[i];
            if(p>1 && q>1){
                mn=max(mn,p+q);
            }
        }

        return n+1-mn;
    }
};