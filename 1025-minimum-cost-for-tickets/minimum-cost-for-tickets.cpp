class Solution {
public:
    int f(int k, vector<int> &arr, vector<int>& days,vector<int> &dp){

        int ub=lower_bound(days.begin(),days.end(),k)-days.begin();
        // ub--;
        if(ub >= days.size()){
            return 0;
        }

        if(dp[k] != -1)
            return dp[k];

        int a=arr[0]+f(days[ub]+1,arr,days,dp);
        int b=arr[1]+f(days[ub]+7,arr,days,dp);
        int c=arr[2]+f(days[ub]+30,arr,days,dp);

        return dp[k]=min(a,min(b,c));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n=days.size();
        int m=days[n-1];
        vector<int>dp(m+1,-1);
        return f(0,costs,days,dp);
    }
};