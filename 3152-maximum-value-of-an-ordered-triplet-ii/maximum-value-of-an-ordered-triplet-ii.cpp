class Solution {
    #define ll long long
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll n=nums.size();
        vector<ll>a(n),b(n);
        a[0]=(ll)nums[0];
        b[n-1]=(ll)nums[n-1];
        for(ll i=1; i<n; i++){
            a[i]=max((ll)nums[i-1],a[i-1]);
        }
        for(ll i=n-2; i>=0; i--){
            b[i]=max(b[i+1],(ll)nums[i+1]);
        }
        ll cp=0;
        for(ll i=1; i<n-1; i++){
            ll k=(ll)(a[i]-(ll)nums[i])*(b[i]);
            cp=max(cp,k);
        }

        return cp;
    }
};