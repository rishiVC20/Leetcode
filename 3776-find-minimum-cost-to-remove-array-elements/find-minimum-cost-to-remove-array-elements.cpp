class Solution {
public:
    int solve(vector<vector<int>>&dp, int idx, int prev, vector<int>&nums){
        int n=nums.size();
        if(idx>=n)
            return 0;

        if(idx==n-1){
            if(idx%2){
                return max(nums[idx],nums[prev]);
            }
            else{
                vector<pair<int,int>>v;
                v.push_back({nums[idx],idx});
                v.push_back({nums[idx-1],idx-1});
                v.push_back({nums[prev],prev});
                sort(v.begin(),v.end());
                return v[0].first+v[2].first;
            }
        }    
        if(dp[idx][prev]!=-1)
            return dp[idx][prev];

        if(idx%2){
            return dp[idx][prev]=solve(dp,idx+1,prev,nums);
        }   
        else{
                vector<pair<int,int>>v;
                v.push_back({nums[idx],idx});
                v.push_back({nums[idx-1],idx-1});
                v.push_back({nums[prev],prev});
                sort(v.begin(),v.end());
                dp[idx][prev]=min(solve(dp,idx+1,v[0].second,nums)+v[2].first,solve(dp,idx+1,v[2].second,nums)+v[1].first);
                return dp[idx][prev];
        }
    }
    int minCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        if(n==1)
            return nums[0];
        if(n==2){
            return max(nums[0],nums[1]);
        }    
        vector<pair<int,int>>v;
        v.push_back({nums[0],0}),v.push_back({nums[1],1}),v.push_back({nums[2],2});
        sort(v.begin(),v.end());
        int a=solve(dp,3,v[0].second,nums)+v[2].first;
        int b=solve(dp,3,v[2].second,nums)+v[1].first;
        cout<<a<<' '<<b<<' ';
        // return min(solve(dp,3,v[0].second,nums)+v[2].first,solve(dp,3,v[2].second,nums)+v[1].first);

        return solve(dp,2,0,nums);
    }
};