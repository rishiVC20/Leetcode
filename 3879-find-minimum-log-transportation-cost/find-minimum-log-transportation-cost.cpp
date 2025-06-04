class Solution {
    #define ll long long
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n<=k && m<=k){
            return 0;
        }

        ll m1=0;
        if(n>k){
            ll rem=n-k;
            m1=k*rem;
        }
        ll m2=0;
        if(m>k){
            ll rem=m-k;
            m2=k*rem;
        }

        return m1+m2;
    }
};