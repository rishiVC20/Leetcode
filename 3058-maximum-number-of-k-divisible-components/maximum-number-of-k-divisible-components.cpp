class Solution {
    #define ll long long
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>>mp;

        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }

        vector<bool>f(n,false);
        vector<int>par(n);
        vector<int>vv;
        f[0]=true;
        par[0]=-1;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int fr=q.front();
            q.pop();
            vv.push_back(fr);
            for(auto i:mp[fr]){
                if(!f[i]){
                    q.push(i);
                    par[i]=fr;
                    f[i]=true;
                }
            }
        }
        // for(auto i:vv)
        //     cout<<i<<' ';
        int ans=0;
        vector<ll>dd;
        for(auto i:values){
            dd.push_back((ll)i);
        }
        for(int i=vv.size()-1; i>=0; i--){
            if(dd[vv[i]]%k==0){
                ans++;
            }
            else{
                dd[par[vv[i]]] += dd[vv[i]];
            }
        }
        
        return ans;

    }
};