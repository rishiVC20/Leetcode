class Solution {
    #define ll long long
    const ll mod=1e9+7;
public:
    bool f(ll val, vector<int> &v, ll m){
        ll t=0,tr=0,s=0;
        for(ll i=0; i<v.size() && t<=m; i++){
            ll req=(val+v[i]-1)/v[i];

            if(tr>=req){
                s++;
                tr=0;
            }
            else{
                ll p=tr*v[i];
                ll ops=((val-p)+v[i]-1)/v[i];
                t+=2*ops-1;
                // t=t%(mod);
                t+=s;
                tr=max(0LL,ops-1);
                s=0;
            }
        }

        return t<=m;
    }
    long long maxScore(vector<int>& points, int m) {
        ll l=0,r=1e18;
        ll n=points.size();
        if(m<n)
            return 0;
        ll ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            ll op=0;
            // for(ll i=0; i<n; i++){
            //     op+=(mid/points[i]);
            // }
            if(f(mid,points,m)){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }

        return ans;
    }
};