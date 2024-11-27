class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>dis(n);
        for(int i=0; i<n; i++){
            dis[i]=i;
        }

        vector<vector<int>>v(n);
        for(int i=0; i<n-1; i++){
            v[i].push_back(i+1);
        }

        vector<int>ans;

        for(int i=0; i<queries.size(); i++){
            int x=queries[i][0],y=queries[i][1];
            v[x].push_back(y);
            if(dis[x]+1 < dis[y]){
                dis[y]=dis[x]+1;
                queue<int>q;
                q.push(y);
                while(!q.empty()){
                    int t=q.front();
                    q.pop();
                    for(auto j:v[t]){
                        if(dis[j]>dis[t]+1){
                            dis[j]=dis[t]+1;
                            q.push(j);
                        }
                        
                    }
                }
            }
            ans.push_back(dis[n-1]);
        }

        return ans;
    }
};