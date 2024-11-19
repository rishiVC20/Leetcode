class Solution {
    #define ll long long 
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll n=nums.size();
        ll i=0, j=k+1;
        set<ll>st;
        map<ll,ll>mp;
        ll s=0;
        for(int i=0; i<k; i++){
            st.insert(nums[i]);
            mp[nums[i]]++;
            s += nums[i];
            // if(st.size()==(i+1))
            //     s += nums[i];
            // else
            //     s=0;    
        }
        ll maxi;
        if(st.size() == k)
            maxi=s;
        else
            maxi=0;   
        // cout<<maxi<<' '; 
        // for(auto i:st)
        //     cout<<i<<' ';
        // cout<<endl;  
        // cout<<s<<' ';  
        for(ll p=k; p<n; p++){
            s -= nums[p-k];

            if(mp[nums[p-k]] == 1){
                st.erase(nums[p-k]);
            }
            mp[nums[p-k]]--;
            st.insert(nums[p]);
            mp[nums[p]]++;
            s += nums[p];
            if(st.size() == k)
                maxi=max(maxi,s);
            // for(auto i:st)
            //     cout<<i<<' ';
            // cout<<endl;    
            // cout<<s<<' ';    
        }

        return maxi;
    }
};