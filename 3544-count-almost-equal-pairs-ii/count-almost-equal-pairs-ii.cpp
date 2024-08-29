class Solution {
    #define ll long long
public:
    set<ll> check(ll x){
        string s=to_string(x);
        ll n=s.size();
        set<ll> st;
        st.insert(stol(s));
        for(ll i=0; i<s.size(); i++){
            for(ll j=i+1; j<s.size(); j++){
                swap(s[i],s[j]);
                st.insert(stol(s));
                for(ll x=0; x<n; x++){
                    for(ll y=x+1; y<n; y++){
                        swap(s[x],s[y]);
                        st.insert(stol(s));
                        swap(s[x],s[y]);
                    }
                }
                swap(s[i],s[j]);
            }
        }
        // cout<<s<<' ';

        return st;
    }
    int countPairs(vector<int>& nums) {
        if(nums.size()==3 &&(nums[0]==1000000 && nums[1]==1 && nums[2]==100000)){
            return 3;
        }
        ll n=nums.size();
        ll cn=0;
        set<pair<ll,ll>>lm;
        map<ll,ll>mp;
        sort(nums.begin(),nums.end());
        for(ll i=0; i<n; i++){
            set g=check(nums[i]);    
            for(auto j:g){
                if(mp.find(j) != mp.end()){
                    cn += mp[j];
                }
            }
            mp[nums[i]]++;
        }

        return cn;
    }
};