class Solution {
    #define ll long long
public:
    vector<ll>u={-1,1,0,0};
    vector<ll>v={0,0,-1,1};
    int orangesRotting(vector<vector<int>>& grid) {
        ll n=grid.size();
        ll m=grid[0].size();
        vector<vector<ll>>vis(n,vector<ll>(m,0));
        queue<pair<pair<ll,ll>,ll>>q;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                    
            }
        }
        
        ll ans=0;
        while(!q.empty()){
            ll x=q.front().first.first;
            ll y=q.front().first.second;
            ll z=q.front().second;
            q.pop();
            ans=max(ans,z);
            for(ll k=0; k<4; k++){
                ll m1=x+u[k];
                ll m2=y+v[k];
                if((m1>=0 && m1<n) && (m2>=0 && m2<m) && grid[m1][m2]==1 && vis[m1][m2]==0){
                    q.push({{m1,m2},z+1});
                    vis[m1][m2]=2;
                }
            }

        }
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]==1)
                    return -1;
            }
        }

        return ans;
    }
};