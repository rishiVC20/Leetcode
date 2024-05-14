class Solution {
public:
    // int 
    void checkMax(vector<vector<int>>& store, vector<vector<int>>& grid, int i, int j)
    {
        int maxi = INT_MIN;
        for (int k=i; k<i+3; k++)
        {
            for (int l=j; l<j+3; l++)
            {
                maxi = max(maxi,grid[k][l]);
            }
        }
        store[i][j] = maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> store(n-2,vector<int>(m-2,0));
        
        for (int i=0; i<n-2; i++)
        {
            for (int j=0; j<m-2; j++)
            {
                checkMax(store,grid,i,j);
            }
        }

        return store;
    }
};