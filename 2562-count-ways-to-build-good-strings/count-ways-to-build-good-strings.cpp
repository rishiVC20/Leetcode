class Solution {
    const int mod=1e9+7;
    #define ll long long
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<ll>dp(high+1,0);
        dp[0]=1;

        for(ll i=1; i<=high; i++){
            if(i>=zero){
                dp[i]+=dp[i-zero];
                dp[i]=dp[i]%mod;
            }
            if(i>=one){
                dp[i]+=dp[i-one];
                dp[i]=dp[i]%mod;
            }
            dp[i]=dp[i]%mod;
        }

        ll cn=0;

        for(ll i=low; i<=high; i++){
            cn += dp[i];
            cn=cn%mod;
        }

        return (ll)cn;  
    }
};