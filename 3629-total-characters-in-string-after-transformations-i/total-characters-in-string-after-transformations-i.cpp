class Solution {
    #define ll long long
    const int mod=1e9+7;
public:
    int lengthAfterTransformations(string s, int t) {
        ll n=s.size();
        vector<ll>a(26,0);
        for(auto i:s){
            a[i-'a']++;
        }

        for(ll i=0; i<t; i++){
            vector<ll>v(26,0);
            for(ll j=0; j<26; j++){
                if(j==25){
                    v[0] += (a[j]%mod);
                    v[1] += (a[j]%mod);
                    break;
                }
                v[j+1]=(a[j]%mod);
            }
            a=v;
        }

        ll cn=0;
        for(auto i:a){
            cn += i;
            cn=(cn%mod);
        }

        return cn;
    }
};