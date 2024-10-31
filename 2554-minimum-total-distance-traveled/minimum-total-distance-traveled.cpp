class Solution {
    #define ll long long
public:
    ll solve(ll rb, ll fac, vector<int>&robot, vector<ll>&a, vector<vector<ll>>&dp){
        if(rb == robot.size())
            return 0;

        if(fac == a.size())
            return 1e12;

        if(dp[rb][fac] != -1)
            return dp[rb][fac];

        ll pick = (ll)(abs((ll)robot[rb]-a[fac]) + (ll)solve(rb+1,fac+1,robot,a,dp));

        ll nopick = solve(rb,fac+1,robot,a,dp);

        return dp[rb][fac] = min(pick,nopick);        
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ll n=robot.size();
        vector<ll>a;
        vector<ll>b(n+1,INT_MAX);
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        
        for(auto i:factory){
            for(ll j=0; j<i[1]; j++)
                a.push_back(i[0]);
        }
        vector<vector<ll>>dp(n+1,vector<ll>(a.size()+1,-1));
        ll k=solve(0,0,robot,a,dp);

        return k;
    }
};