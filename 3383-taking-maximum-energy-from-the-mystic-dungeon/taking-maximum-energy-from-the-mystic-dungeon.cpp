class Solution {
public:
    int rec(int p, vector<int>&energy, int k, vector<int> &dp)
    {
        if (p >= energy.size())
            return 0;

        if (dp[p] != -1)
            return dp[p];

        dp[p] = energy[p] + rec(p+k,energy,k,dp);

        return dp[p];    
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int maxi = INT_MIN;
        int n=energy.size();
        vector<int>dp(n+1,-1);
        for (int i=0; i<n; i++)
        {
            maxi = max(maxi,rec(i,energy,k,dp));
        }
        return maxi;
    }
};