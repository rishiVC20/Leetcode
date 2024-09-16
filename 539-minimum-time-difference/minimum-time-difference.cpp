class Solution {
    #define ll long long
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<ll>v;
        ll n=timePoints.size();
        for(ll i=0; i<n; i++){
            string s=timePoints[i].substr(0,2);
            ll k=stol(s);
            k=k*60*60;
            string s1=timePoints[i].substr(3,2);
            ll m=stol(s1);
            k += m*60;
            v.push_back(k);
        }
        sort(v.begin(),v.end());
        for(ll i=0; i<n; i++)
            v.push_back(v[i]);
        ll mini=INT_MAX;
        ll u=24*60*60;
        for(ll i=0; i<2*n-1; i++){
            // cout<<v[i]<<' ';
            mini = min(mini,abs(v[i+1]-v[i]));
            ll mn=(u-max(v[i+1],v[i]))+min(v[i],v[i+1]);
            mini=min(mini,mn);
        }    
        ll t=mini/60;

        return t;
    }
};