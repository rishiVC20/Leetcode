class Solution {
public:
    int row[4]={0,0,1,-1};
    int col[4]={1,-1,0,0};
    void solve(vector<vector<char>>& grid, int i, int j){
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0')
            return;
        grid[i][j]='0';
        for (int k=0; k<4; k++){
            solve(grid,i+row[k],j+col[k]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cn = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]=='1'){
                    cn++;
                    solve(grid,i,j);
                }
            }
        }

        return cn;
    }
};