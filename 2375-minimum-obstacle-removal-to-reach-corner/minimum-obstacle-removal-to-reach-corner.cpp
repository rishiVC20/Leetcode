class Solution {
public:
    vector<int> a={1,-1,0,0};
    vector<int> b={0,0,1,-1};

    void solve(vector<vector<int>> &grid, vector<int> &d, int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &ans){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || vis[i][j]){
            return;
        }
        if(grid[i][j]==1){
            d.push_back(1);
        }
        else{
            d.push_back(0);
        }
        if(i==0 && j==0){
            ans.push_back(d);
            return;
        }
        vis[i][j]=true;
        for(int k=0; k<4; k++){
            solve(grid,d,i+a[k],j+b[k],vis,ans);
            // solve(grid,d,i+d)
        }
        vis[i][j]=false;
        d.pop_back();
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>>ans;
        vector<int>d;
        int m=grid.size();
        int n=grid[0].size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({0,0,0});
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            int ob=curr[0],x=curr[1],y=curr[2];

            if(x==m-1 && y==n-1){
                return ob;
            }

            for(int k=0; k<4; k++){
                int nx=x+a[k],ny=y+b[k];

                if(nx>=0 && ny>=0 && nx<m && ny<n){
                    int newob=ob+grid[nx][ny];

                    if(newob < dis[nx][ny]){
                        dis[nx][ny]=newob;
                        pq.push({newob,nx,ny});
                    }
                }
            }
        }

        return -1;
    }
};