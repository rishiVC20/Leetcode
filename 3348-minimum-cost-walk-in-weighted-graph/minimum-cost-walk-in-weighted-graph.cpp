#define ll long long
class Disjoint{
    vector<ll>size,rank,parent;
public:
    Disjoint(ll n){
        size.resize(n+1,1);
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(ll i=0; i<=n; i++)
            parent[i]=i;
    }
    ll findParent(ll node){
        if(node==parent[node])
            return node;
        return parent[node]=(findParent(parent[node]));
    }
    void unionBySize(ll u, ll v){
        ll ulp_u=findParent(u);
        ll ulp_v=findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<ll>>adj(n);
        vector<vector<ll>>pk(n);
        Disjoint d1((ll)n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            // pk[i[0]].push_back(i[2]);
            // pk[i[1]].push_back(i[2]);
            d1.unionBySize(i[0],i[1]);
        }
        for(auto i:edges){
            int u=d1.findParent(i[0]);
            int v=d1.findParent(i[1]);
            if(u==v){
                pk[u].push_back(i[2]);
            }
        }
        set<int>st;
        for(int i=0; i<n; i++){
            int par=d1.findParent(i);
            st.insert(par);
        }
        map<int,int>mp;
        for(auto i:st){
            int t=-1;
            for(auto j:pk[i]){
                if(t==-1){
                    t=j;
                    continue;
                }
                t&=j;
            }
            mp[i]=t;
        }

        vector<int>ans;
        for(auto i:query){
            ll u=i[0],v=i[1];
            int r1=d1.findParent(u);
            int r2=d1.findParent(v);
            if(r1!=r2){
                ans.push_back(-1);
                continue;
            }
            int k=-1;
            // vector<int>t=pk[r1];
            // for(auto j:pk[r1]){
            //     // cout<<j<<' ';
            //     if(k==-1){
            //         k=j;
            //         continue;
            //     }
            //     k&=j;
            //     if(k==0){
            //         break;
            //     }
            // }
            // cout<<k<<' ';
            // for(auto j:pk[v]){
            //     k&=j;
            // }
            if(mp.find(r1)!=mp.end()){
                k=mp[r1];
            }
            ans.push_back(k);
        }

        return ans;
    }
};