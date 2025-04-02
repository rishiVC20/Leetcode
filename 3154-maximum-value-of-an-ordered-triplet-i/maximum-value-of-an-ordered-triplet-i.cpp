class Solution {
    #define ll long long
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll mx=0;
        ll n=nums.size();
        for(ll i=0; i<n; i++){
            for(ll j=i+1; j<n; j++){
                for(ll k=j+1; k<n; k++){
                    mx=max(mx,((ll)nums[i]-(ll)nums[j])*(ll)nums[k]*1LL);
                }
            }
        }

        return mx;
    }
};