class Solution {
public:
    void solve(unordered_map<int,vector<int>> &adj, vector<int> &v, int i){

        while(!adj[i].empty()){
            int next=adj[i].back();
            adj[i].pop_back();
            solve(adj,v,next);
        }
        v.push_back(i);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        unordered_map<int, vector<int>> adj;
        unordered_map<int,int>out,in;
        for(auto i:pairs){
            adj[i[0]].push_back(i[1]);
            out[i[0]]++,in[i[1]]++;
        }

        int u=-1;
        int sz=0;
        for(auto [node,i]:out){
            // if(j.second.size()%2==0 && j.second.size()>sz){
            //     sz=j.second.size(),u=j.first;
            // }
            if(i > in[node]){
                u=node;
                break;
            }
        }
        // cout<<u<<' ';
        if(u==-1)
            u=pairs[0][0];

        vector<int>v;
        solve(adj,v,u);    

        // for(auto i:v)
        //     cout<<i<<' ';


        reverse(v.begin(),v.end());
        vector<vector<int>>ans;
        for(int i=0; i<v.size()-1; i++){
            ans.push_back({v[i],v[i+1]});
        }   
        // vector<vector<int>> result;
        // for (auto& p : adj) {
        //     for (auto q : p.second) {
        //         result.push_back({p.first, q});
        //     }
        // }

        // return result; 

        return ans;

    }
};