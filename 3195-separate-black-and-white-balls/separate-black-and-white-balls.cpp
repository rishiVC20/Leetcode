class Solution {
    #define ll long long
public:
    long long minimumSteps(string s) {
        ll n=s.size();
        ll i=0,j=n-1;
        ll cn=0;
        ll sum=0;
        for(ll i=n-1; i>=0; i--){
            if(s[i]=='0'){
                sum++;
            }
            else{
                cn += sum;
            }
        }

        return cn;
    }
};