class Solution {
    #define ll long long
public:
    ll solve(string str, string suf, ll lmt){
        if(str.size()<suf.size()){
            return 0;
        }

        ll cn=0;
        ll rem=str.size()-suf.size();
        for(ll i=0; i<rem; i++){
            ll dg=str[i]-'0';
            if(dg<=lmt){
                cn+=dg*pow(lmt+1,rem-i-1);
            }
            else{
                cn+=pow(lmt+1,rem-i);
                return cn;
            }
        }

        string news=str.substr(rem);
        // cout<<news<<' ';
        if(news>=suf){
            cn++;
        }

        return cn;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {

        return solve(to_string(finish),s,limit) - solve(to_string(start-1),s,limit);
        
    }
};