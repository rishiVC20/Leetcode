class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>mp;
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            mp[u].push_back({v,succProb[i]});
            mp[v].push_back({u,succProb[i]});
        }
        priority_queue<pair<int,double>>pq;
        vector<double>res(n,0);
        res[start_node]=1;
        pq.push({start_node,1.0});
        while(!pq.empty()){
            auto it=pq.top();
            int x=it.first;
            double y=it.second;
            pq.pop();
            for(auto i:mp[x]){
                int k=i.first;
                double m=i.second;
                if(res[k] < m*y){
                    res[k]=m*y;
                    pq.push({k,res[k]});
                }
                
            }
            
        }
        for(auto i:res)
            cout<<i<<' ';
        return res[end_node];
    }
};