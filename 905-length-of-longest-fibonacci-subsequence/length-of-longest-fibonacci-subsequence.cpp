class Solution {
    #define ll long long
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        ll n=(ll)arr.size();

        vector<vector<ll>>dp(n,vector<ll>(n,0));

        map<ll,ll>mp;
        for(ll i=0; i<n; i++){
            for(ll j=i+1; j<n; j++){
                // ll k=2;
                ll m=arr[j]-arr[i];
                ll k=-1;
                if(mp.find(m)!=mp.end()){
                    k=mp[m];
                }
                if(k==-1){
                    dp[i][j]=2;
                }
                else{
                    ll t=dp[k][i];
                    dp[i][j]=t+1;
                }
            }
            mp[arr[i]]=i;
        }

        ll maxi=0;
        for(auto i:dp){
            for(auto j:i){
                if(j>2)
                    maxi=max(maxi,j);
            }
        }

        return maxi;
    }
};