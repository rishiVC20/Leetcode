#define ll long long
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<ll,vector<pair<ll,double>>>mp;
        for(ll i=0; i<edges.size(); i++){
            ll x=edges[i][0],y=edges[i][1];
            mp[x].push_back({y,succProb[i]});
            mp[y].push_back({x,succProb[i]});
        }
        priority_queue<pair<ll,double>>pq;
        vector<double>v(n,0);
        pq.push({start_node,1.0});
        v[start_node]=1;
        while(!pq.empty()){
            auto it=pq.top();
            ll k=it.first;
            double q=it.second;
            pq.pop();
            for(auto i:mp[k]){
                ll c=i.first;
                double d=i.second;
                if(v[c]<d*q){
                    v[c]=d*q;
                    pq.push({c,d*q});
                }
                
            }
        }

        return v[end_node];
    }
};