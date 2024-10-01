class Solution {
    #define ll long long
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        set<ll>st;
        sort(maximumHeight.rbegin(),maximumHeight.rend());
        vector<int>nums=maximumHeight;
        st.insert(maximumHeight[0]);
        ll n=maximumHeight.size();
        for(ll i=1; i<n; i++){
            if(maximumHeight[i] >= maximumHeight[i-1]){
                maximumHeight[i] = maximumHeight[i-1]-1;
            }
            if(maximumHeight[i]<=0)
                return -1;

        }
        // for(auto i:maximumHeight)
        //     cout<<i<<' '; 
        ll sum=accumulate(maximumHeight.begin(),maximumHeight.end(),0LL);

        return sum;
    }
};