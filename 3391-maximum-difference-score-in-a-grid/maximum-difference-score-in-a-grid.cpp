class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int sol = INT_MIN;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                int mini = INT_MAX;
                if (i!=0)
                    mini = min(mini,grid[i-1][j]);
                if (j!=0)
                    mini = min(mini,grid[i][j-1]);
                sol = max(sol,grid[i][j]-mini);
                cout<<sol<<" ";
                grid[i][j] = min(grid[i][j],mini);            
            }
        }

        return sol;
    }
};