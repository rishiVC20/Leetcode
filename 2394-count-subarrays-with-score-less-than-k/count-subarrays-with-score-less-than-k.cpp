class Solution {
    #define ll long long
public:
    ll cn=0;
    void solve(vector<int>&a, ll st, ll en, vector<ll>&pre, ll k){
        if(en==pre.size())
            return;

        if(st>en){
            solve(a,1,en+1,pre,k);
        }    
        else{
            // cout<<"hi ";
            int sm=pre[en]-pre[st-1];
            ll sc=sm*(en-st+1);
            // cout<<sm<<' '<<sc<<' ';
            if(sc<k){
                cn++;
            }
            solve(a,st+1,en,pre,k);
        }
    }
    long long countSubarrays(vector<int>& nums, long long k) {
        // vector<ll>pre;
        // pre.push_back(0);
        // for(ll i=0; i<nums.size(); i++){
        //     pre.push_back(pre.back()+nums[i]);
        // }
        // cn=0;
        // solve(nums,1,1,pre,k);

        // return cn;

        ll cn=0;
        ll sum=0;
        ll l=0;

        for(ll r=0; r<nums.size(); r++){
            sum+=nums[r];

            while(l<=r && sum*(r-l+1)>=k){
                sum-=nums[l];
                l++;
            }

            if(l<=r){
                cn+=(r-l+1);
            }
        }

        return cn;
    }
};