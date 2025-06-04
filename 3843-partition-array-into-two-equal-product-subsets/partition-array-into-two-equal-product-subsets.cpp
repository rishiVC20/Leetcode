class Solution {
    #define ll long long
    const int mod=1e9+7;
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll n=nums.size();
        for(int i=0; i<nums.size(); i++){
            if(target%nums[i]!=0){
                return false;
            }
        }
        
        vector<ll>dp(n,0);
        auto rec=[&](auto &self, ll ind, ll cal)->bool{
            if(ind>=n || cal>target){
                return false;
            }
            if(cal==target){
                return true;
            }
            cal=cal*nums[ind];
            dp[ind]=1;
            bool k1=self(self,ind+1,cal);
            cal/=nums[ind];
            if(k1){
                return true;
            }
            dp[ind]=0;
            bool k2=self(self,ind+1,cal);
            return k1||k2;
        };

        bool rep=rec(rec,0,1);
        cout<<rep;
        if(rep){
            ll rk=1;
            for(ll i=0; i<n; i++){
                if(dp[i]==0){
                    rk=(rk*nums[i]);
                }
            }

            return rk==target;
        }

        return false;
    }
};