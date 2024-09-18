class Solution {
    #define ll long long
public:
    vector<int>u={-1,1,0,0};
    vector<int>v={0,0,-1,1};
    bool solve(int i, int j, vector<vector<int>>&grid, int &health,int x, int y,vector<vector<int>>&dp){
        if(i==0 && j==0)
            return true;
        if(i<0 || i>=x || j<0 || j>=y)
            return false;
        if(dp[i][j] != -1)
            return dp[i][j];    
        if(grid[i][j]==1){
            health--;
            if(health < 0){
                dp[i][j]=0;
                return false;
            }
        }        
        // for(ll k=0; k<4; k++){
        //     bool p1=solve()
        // }
        bool p1=solve(i+u[0],j+v[0],grid,health,x,y,dp);
        bool p2=solve(i+u[1],j+v[1],grid,health,x,y,dp);
        bool p3=solve(i+u[2],j+v[2],grid,health,x,y,dp);
        bool p4=solve(i+u[3],j+v[3],grid,health,x,y,dp);
        if(p1||p2||p3||p4)
            dp[i][j]=1;
        else
            dp[i][j]=0;    
        return dp[i][j];
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int x=grid.size();
        int y=grid[0].size();
        // vector<vector<int>>dp(x,vector<int>(y,-1));
        // return solve(x-1,y-1,grid,health,x,y,dp);
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(x,vector<int>(y,-1));
        if(grid[x-1][y-1]==1)
            health--;
        q.push({{x-1,y-1},health});
        while(!q.empty()){
            int aa=q.front().first.first;
            int bb=q.front().first.second;
            int cc=q.front().second;
            q.pop();
            if(aa==0 && bb==0 && cc>=1)
                return true;
            // vector<bool>m(4);
            for(int i=0; i<4; i++){
                int v1=aa+u[i];
                int v2=bb+v[i];
                if(v1<0 || v1>=x || v2<0 || v2>=y){
                    continue;
                }
                int newh=cc;
                if(grid[v1][v2]==1){
                    newh--;
                }
                if(newh>=1 && (vis[v1][v2]==-1 || vis[v1][v2] < newh)){
                    vis[v1][v2]=newh;
                    q.push({{v1,v2},newh});
                }
            }

        }

        return false;
    }
};