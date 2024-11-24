class Solution {
    #define ll long long
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        ll cn=0;

        ll n=s.size();
        for(ll i=0; i<n; i++){
            ll x=s[i]-'a',y=t[i]-'a';
            ll s1=0,s2=0;
            if(x==y)
                continue;

            if(x<y){
                s1 += accumulate(previousCost.begin(),previousCost.begin()+x+1,0LL)+accumulate(previousCost.begin()+y+1,previousCost.end(),0LL);
                s2 += accumulate(nextCost.begin()+x,nextCost.begin()+y,0LL);
                // cout<<s1<<"h "<<s2<<endl;
            }    
            else{
                s1+=accumulate(nextCost.begin()+x,nextCost.end(),0LL)+accumulate(nextCost.begin(),nextCost.begin()+y,0LL);
                s2+=accumulate(previousCost.begin()+y+1,previousCost.begin()+x+1,0LL);
                // cout<<s1<<"k "<<s2<<endl;
            }

            cn += min(s1,s2);
        }

        return cn;
    }
};