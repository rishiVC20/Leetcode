class Solution {
    #define ll long long
public:
    
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        ll n=nums.size();
        set<ll>st;
        ll cn=0;
        for(auto i:nums)
            st.insert(i);

        for(ll i=0; i<n; i++){
            ll t=nums[i];
            ll mm=1;
            for(int j=0; j<5; j++){
                if(st.find(t*t) != st.end()){
                    mm++;
                    t=t*t;
                }
                else{
                    break;
                }
            }
            cn=max(cn,mm);
        }    

        if(cn<2)
            return -1;


        return cn;    
    }
};