class Solution {
public:
    int solve(int k,vector<vector<int>>& books, int shelf, vector<int>& dp){
        if (k>=books.size())
            return 0;
        if (dp[k] != -1){
            return dp[k];
        }
        int w=0, h=0;
        int ans = INT_MAX;
        for (int i=k; i<books.size(); i++){
            w += books[i][0];
            if (w>shelf)
                break;
            h = max(h,books[i][1]);    
            ans = min(ans,h + solve(i+1,books,shelf,dp));    
        }    

        return dp[k] = ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int>dp(n,-1);
        return solve(0,books,shelfWidth,dp);
    }
};