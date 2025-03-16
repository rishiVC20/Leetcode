class Solution {
    #define ll long long
public:
    bool check(vector<int>&ranks, int cars, ll t){
        int n=ranks.size();
        for(int i=0; i<n; i++){
            ll q=sqrt(t/ranks[i]);
            cars-=q;
            if(cars<=0)
                return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll l=1,r=1e18;
        ll ans;
        while(l<=r){
            ll md=(l+r+1)/2;
            if(check(ranks,cars,md)){
                ans=md;
                r=md-1;
            }
            else{
                l=md+1;
            }
        }

        return ans;
    }
};