class Solution {
    #define ll long long
public:
    int uniqueXorTriplets(vector<int>& nums) {
        ll n=nums.size();
        unordered_set<ll>st,s1;
        for(ll i=0; i<n; i++){
            st.insert(nums[i]);
            for(ll j=i+1; j<n; j++){
                ll p=nums[i]^nums[j];
                s1.insert(p);
            }
        }

        for(ll i=0; i<n; i++){
            for(auto j:s1){
                st.insert((ll)nums[i]^j);
            }
        }

        return (int)st.size();
    }
};