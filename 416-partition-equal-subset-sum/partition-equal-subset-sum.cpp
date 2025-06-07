class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1){
            return false;
        }
        int md=sum/2;
        vector<vector<int>>dp(n,vector<int>(md+1,-1));
        auto solve=[&](auto &self, int ind, int cal)->bool{
            if(ind==n || cal>md){
                return false;
            }
            if(cal==md){
                return true;
            }

            if(dp[ind][cal]!=-1){
                return dp[ind][cal];
            }

            // cal+=nums[ind];
            bool t1=self(self,ind+1,cal+nums[ind]);
            // cal-=nums[ind];
            bool t2=self(self,ind+1,cal);

            return dp[ind][cal]=t1|t2;

        };

        return solve(solve,0,0);
    }
};