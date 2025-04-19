class Solution {
    #define ll long long
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        ll n=nums.size();
        ll cn=0;
        for(ll i=0; i<n; i++){
            ll x=lower-nums[i];
            ll y=upper-nums[i];
            ll tr=lower_bound(nums.begin(),nums.end(),x)-nums.begin();
            ll tp=upper_bound(nums.begin(),nums.end(),y)-nums.begin();
            tp--;
            // cout<<i<<' '<<tr<<' '<<tp<<endl;

            if(tp>=tr){
                cn+=tp-tr+1;
            }
            if(i>=tr && i<=tp){
                cn--;
            }
        }

        return cn/2;
    }
};