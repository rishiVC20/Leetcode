class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxx = -1;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j])
                    maxx = i;
            }
        }
        int minx = -1;
        bool f = false;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (grid[i][j]){
                    minx = i;
                    f = true;
                    break;
                }
            }
            if (f)
                break;
        }
        int maxy = -1;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[j][i])
                    maxy = i;
            }
        }
        int miny = -1;
        f = false;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[j][i]){
                    miny = i;
                    f = true;
                    break;
                }
            }
            if (f)
                break;
        }
        // if (maxx==-1 || maxy==-1)
        //     return 0;

        int cp;
        if (maxx-minx == 0)
            cp = 1;
        else
            cp = maxx-minx + 1;
        int kp;
        if (maxy-miny == 0)
            kp = 1;
        else
            kp = maxy-miny + 1;

        return cp*kp;                
    }
};