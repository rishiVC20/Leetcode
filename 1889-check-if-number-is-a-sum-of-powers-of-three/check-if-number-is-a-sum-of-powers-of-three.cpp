class Solution {
    #define ll long long
public:
    bool checkPowersOfThree(int n) {
        for(int i=16; i>=1; i--){
            ll k=pow(3,i);
            if((ll)n>=k){
                n-=k;
            }
            // cout<<n<<' ';
            if(n==0)
                return true;
        }      

        return n<=1;
    }
};