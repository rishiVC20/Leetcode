class Solution {
    #define ll long long 
    #define pb push_back 
    #define onebit(x) __builtin_popcountll(x)
    #define vi vector<ll>
    #define YES cout<<'Y'<<'E'<<'S'<<endl
    #define NO cout<<'N'<<'O'<<endl
    const ll mod = 1e9+7;
public:
    ll power(ll base, ll exponent)
    {
        if (exponent < 0)
        {
            return 0;
        }
        ll ans = 1;
        while (exponent)
        {
            if (exponent%2==0)
            {
                base = (base*base) % mod;
                exponent = exponent/2;
            }
            else
            {
                ans = (ans*base) % mod;
                exponent--;
            }
        }
        return ans;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier==1)
            return nums;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        ll n=nums.size();
        for(ll i=0; i<n; i++){
            pq.push({nums[i],i});
        }
        // for(auto i:pq){
        //     cout<<i.first<<' '<<i.second<<' ';
        // }
        ll maxi=*max_element(nums.begin(),nums.end());
        while(k>0 && 1LL*multiplier*pq.top().first<=maxi){
            k--;
            auto k=pq.top();
            ll m=k.first;
            pq.pop();
            m = (m*multiplier)%mod;
            pq.push({m,k.second});
        }

        ll left=k/n;
        ll rem=k%n;
        ll b=power(multiplier,left);
        while(!pq.empty()){
            auto p=pq.top();
            ll m1=p.first;
            ll m2=p.second;
            if(rem>0){
                nums[m2] = ((1LL*multiplier*b)%mod*m1)%mod;
                rem--;
            }
            else{
                nums[m2] = (1LL*b*m1)%mod;
            }
            pq.pop();
        }

        return nums;
    }   
};