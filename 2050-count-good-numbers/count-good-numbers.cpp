class Solution {
    #define ll long long
    const int mod=1e9+7;
public:
    ll power(ll base, ll exponent){
        if (exponent < 0){
            return 0;
        }
        ll ans = 1;
        while (exponent){
            if (exponent%2==0){
                base = (base*base) % mod;
                exponent = exponent/2;
            }
            else{
                ans = (ans*base) % mod;
                exponent--;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        // vector<ll>v(n);
        ll cn=1;
        // for(ll i=0; i<n; i++){
        //     if(i&1){
        //         cn=(cn*4)%mod;
        //     }
        //     else {
        //         cn=(cn*5)%mod;
        //     }
        // }

        ll k1=(n+1)/2,k2=n/2;
        cn=power(5,k1);
        cn=cn%mod;
        ll cp=power(4,k2);
        cp=(cp)%mod;
        cn=(cp*cn)%mod;
        return cn;
    }
};