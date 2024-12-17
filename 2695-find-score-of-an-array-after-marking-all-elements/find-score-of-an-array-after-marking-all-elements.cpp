class Solution {
    #define ll long long
public:
    long long findScore(vector<int>& nums) {
        ll n=nums.size();
        vector<pair<ll,ll>>v;
        for(ll i=0; i<n; i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end(),[&](pair<ll,ll>&a, pair<ll,ll> &b){
            if(a.first==b.first)
                return a.second<b.second;
            return a.first < b.first;
        });

        set<ll>p,q;

        for(int i=0; i<n; i++){
            if(q.find(v[i].second)==q.end()){
                q.insert(v[i].second-1);
                q.insert(v[i].second);
                q.insert(v[i].second+1);
                p.insert(v[i].second);
            }
        }

        ll ans=0;
        for(auto i:p){
            cout<<i<<' ';
            ans += nums[i];
        }

        return ans;
    }   
};