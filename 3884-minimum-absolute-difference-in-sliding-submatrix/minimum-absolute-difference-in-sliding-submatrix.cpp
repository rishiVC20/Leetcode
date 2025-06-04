class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            vector<int>dt;
            for(int j=0; j<m; j++){
                if(i+k<=n && j+k<=m){
                    vector<int>dr;
                    for(int u=i; u<i+k; u++){
                        for(int v=j; v<j+k; v++){
                            dr.push_back(grid[u][v]);
                            cout<<"hi ";
                        }
                    }
                    sort(dr.begin(),dr.end());
                    int mini=INT_MAX;
                    for(int e=1; e<dr.size(); e++){
                        if(dr[e]==dr[e-1]){
                            continue;
                        }
                        mini=min(mini,dr[e]-dr[e-1]);
                    }
                    if(mini==INT_MAX){
                        mini=0;
                    }
                    dt.push_back(mini);
                }
            }
            if(dt.size()>0)
                ans.push_back(dt);
        }

        return ans;
    }
};