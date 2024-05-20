class Solution {
public:
    vector<int>row = {-1,1,0,0};
    vector<int>col = {0,0,-1,1};

    int rec(vector<vector<int>>& grid, int r, int c)
    {
        if (r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0)
            return 0;

        int sum = grid[r][c];
        // int k = grid[r][c];
        grid[r][c]=0;
        int maxi = sum;
        // int a = rec(grid,store,r+row[0],c+col[0],sum);
        // int b = rec(grid,store,r+row[1],c+col[1],sum);
        // int d = rec(grid,store,r+row[2],c+col[2],sum);
        // int e = rec(grid,store,r+row[3],c+col[3],sum);
        maxi = max(maxi,sum+rec(grid,r+row[0],c+col[0]));
        maxi = max(maxi,sum+rec(grid,r+row[1],c+col[1]));
        maxi = max(maxi,sum+rec(grid,r+row[2],c+col[2]));
        maxi = max(maxi,sum+rec(grid,r+row[3],c+col[3]));

        
        // store[r][c] = max(a,max(a,max(b,c)));
        grid[r][c] = sum;

        // return max(a,max(b,max(d,e)));
        return maxi;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> store (n,vector<int>(m,0));
        int sum;

        for (int i=0; i<n; i++)
        {
            
            for (int j=0; j<m; j++)
            {
                // sum = 0;
                int g = rec(grid,i,j);
                store[i][j] = g;
            }
        }    

        int maxi = 0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                maxi = max(maxi,store[i][j]);
            }
        }

        return maxi;
    }
};