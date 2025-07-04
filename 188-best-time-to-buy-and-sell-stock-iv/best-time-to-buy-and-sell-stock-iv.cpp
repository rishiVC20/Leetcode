class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        auto solve=[&](auto &self, int ind, int st, int cap)->int{
            if(ind==n || cap==0){
                return 0;
            }

            if(dp[ind][st][cap]!=-1){
                return dp[ind][st][cap];
            }

            int pr=0;
            if(st==0){
                pr=max(self(self,ind+1,0,cap),self(self,ind+1,1,cap)-prices[ind]);
            }
            else{
                pr=max(self(self,ind+1,1,cap),self(self,ind+1,0,cap-1)+prices[ind]);
            }

            return dp[ind][st][cap]=pr;

        };

        return solve(solve,0,0,k);
    }
};