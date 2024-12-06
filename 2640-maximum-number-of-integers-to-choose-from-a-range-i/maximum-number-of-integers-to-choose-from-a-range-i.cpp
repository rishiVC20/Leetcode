class Solution {
public:
    int solve(vector<int>&arr, int i, int sum, vector<int> &dp){
        if(sum<0 || i==arr.size()){
            return 0;
        }
        if(dp[i] != -1)
            return dp[i];
        int pick=0;
        if(sum-arr[i] >= 0)
            pick=1+solve(arr,i+1,sum-arr[i],dp);
        int nopick=solve(arr,i+1,sum,dp);

        return dp[i]=max(pick,nopick);
    }
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        for(auto i:banned){
            st.insert(i);
        }

        vector<int>a;
        for(int i=1; i<=n; i++){
            if(st.find(i)==st.end()){
                a.push_back(i);
            }
        }

        vector<int>dp(a.size()+1,-1);
        return solve(a,0,maxSum,dp);

    }
};