class Solution {
    #define ll long long
public:
    long long countBadPairs(vector<int>& nums) {
        vector<ll>a;
        ll n=nums.size();
        map<ll,ll>mp;
        for(ll i=0; i<n; i++){
            a.push_back(i-nums[i]);
            mp[a[i]]++;
        }

        ll cn=0;
        for(auto i:mp){
            ll h=i.second*(i.second-1)/2;
            cn+=h;
        }
        ll tot=n*(n-1)/2;
        return tot-cn;
    }
};