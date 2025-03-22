class Solution {
    class Disjoint{
    public:
        vector<int>size,parent;
        Disjoint(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0; i<=n; i++){
                parent[i]=i;
            }
        }
        int findParent(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findParent(parent[node]);
        }
        void unionBySize(int u, int v){
            int ulp=findParent(u);
            int vlp=findParent(v);
            if(ulp==vlp)
                return;
            if(size[ulp]<size[vlp]){
                parent[ulp]=vlp;
                size[vlp]+=size[ulp];
            }    
            else{
                parent[vlp]=ulp;
                size[ulp]+=size[vlp];
            }
        }
    };
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        Disjoint d(n);
        for(auto i:edges){
            d.unionBySize(i[0],i[1]);
        }
        vector<vector<int>>adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        map<int,vector<int>>mp;
        for(int i=0; i<n; i++){
            int k=d.findParent(i);
            mp[k].push_back(i);
        }

        int cp=0;
        for(auto i:mp){
            int sz=i.second.size();
            bool f=true;
            vector<int>v=i.second;
            int p=v.size();
            for(auto j:v){
                // cout<<j<<' ';
                int t=adj[j].size();
                // cout<<t<<' '<<p<<' ';
                if(t!=p-1){
                    f=false;
                    // break;
                }
            }
            cout<<endl;
            if(f){
                cp++;
            }
        }

        return cp;
    }
};