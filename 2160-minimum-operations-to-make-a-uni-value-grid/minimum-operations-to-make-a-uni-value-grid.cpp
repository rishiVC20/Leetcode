class Solution {
    #define ll long long
public:
    pair<ll,bool>check(vector<ll> &a, ll md, ll x){
        ll k=0;
        for(auto i:a){
            int df=abs(i-md);
            k+=(df)/x;
            if(df%x!=0){
                return {-1,false};
            }
            
        }
        return {k,true};
    }
    int minOperations(vector<vector<int>>& grid, int x) {
         vector<ll> a;
        for (auto &row : grid) {
            for (auto &val : row) {
                a.push_back(val);
            }
        }

        sort(a.begin(), a.end()); 
        ll median = a[a.size() / 2];
        ll operations = 0;

        for (ll num : a) {
            if (abs(num - median) % x != 0) {
                return -1; 
            }
            operations += abs(num - median) / x; 
        }

        return operations;
        // vector<ll>a;
        // for(auto i:grid){
        //     for(auto j:i){
        //         a.push_back(j);
        //     }
        // }
        // long long l=0, r=1e9;
        // ll ans=LLONG_MAX;
        // while(l<=r){
        //     ll md=(l+r)/2;
        //     pair<ll,bool>d=check(a,md,x);
        //     cout<<md<<' '<<d.first<<' '<<d.second<<endl;
        //     // cout<<l<<' '<<r<<endl;
        //     if(d.second==1){
        //         ans=min(ans,d.first);
        //         r=md-1;
        //     }
        //     else{
        //         l=md+1;
        //     }
        // }
        // if(ans==INT_MAX)
        //     return -1;
        // return ans;
    }
};