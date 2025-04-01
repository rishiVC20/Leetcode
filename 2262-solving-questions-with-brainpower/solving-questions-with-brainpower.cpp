class Solution {
    #define ll long long
public:
    ll solve(ll ind, vector<vector<int>> &a, vector<ll> &dp){
        if(ind>=(ll)a.size()){
            return 0;
        }

        if(dp[ind]!=-1){
            return dp[ind];
        }
        ll m1=a[ind][0]+solve(ind+a[ind][1]+1,a,dp);
        ll m2=solve(ind+1,a,dp);
        return dp[ind]=max(m1,m2); 
    }
    long long mostPoints(vector<vector<int>>& questions) {
        
        ll n=(ll)questions.size();
        vector<ll>dp(n,-1);
        ll p=solve(0,questions,dp);

        return p;
    }
};