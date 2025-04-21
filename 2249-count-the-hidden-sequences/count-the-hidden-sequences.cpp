class Solution {
    #define ll long long
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll mn=INT_MAX,mx=INT_MIN;
        ll cn=0;
        ll n=differences.size();
        for(int i=0; i<n; i++){
            cn+=differences[i];
            mn=min(mn,cn);
            mx=max(mx,cn);
        }
        // if(n==1){
            mx=max(mx,0LL);
            mn=min(mn,0LL);
        // }
        cout<<mn<<' '<<mx<<' ';

        if(lower>mn){
            ll k=lower-mn;
            mx+=k;
        }
        else{
            ll k=mn-lower;
            mx-=k;
        }
        cout<<mx<<' ';

        if(upper<mx){
            return 0;
        }
        return upper-mx+1;
    }
};