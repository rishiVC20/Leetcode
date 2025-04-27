class Solution {
    #define ll long long
    const int mod=1e9+7;
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        ll n=conversions.size();
        vector<int>d(n+1,1);
        // sort(conversions.begin(),conversions.end(),[&](vector<int>&a, vector<int>&b){
        //     return a[0]<b[0];
        // });
        for(auto i:conversions){
            ll k1=i[0],k2=i[1],k3=i[2];
            d[k2]=(d[k1]*k3)%mod;
        }

        return d;
    }
};