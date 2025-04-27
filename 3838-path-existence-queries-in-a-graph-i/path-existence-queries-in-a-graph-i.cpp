class Solution {
public:
    class Disjoint{
        public:
        vector<int>par;
        vector<int>size;
        Disjoint(int n){
            par.resize(n+1);
            size.resize(n+1,1);
            for(int i=0; i<=n; i++){
                par[i]=i;
            }
        }
        int findParent(int g){
            if(par[g]==g){
                return g;
            }
            return par[g]=findParent(par[g]);
        }
        void unionBySize(int u, int v){
            int paru=findParent(u);
            int parv=findParent(v);
            if(paru==parv)
                return;
            if(size[paru]>size[parv]){
                size[parv]+=size[paru];
                par[paru]=parv;
            }    
            else{
                size[paru]+=size[parv];
                par[parv]=paru;
            }
        }
    };
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        Disjoint d(n);
        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                d.unionBySize(i,i-1);
            }
        }
        for(int i=0; i<n; i++){
            cout<<d.findParent(i)<<' ';
        }
        vector<bool>qr;
        for(auto i:queries){
            if(d.findParent(i[0]) == d.findParent(i[1])){
                qr.push_back(true);
            }
            else{
                qr.push_back(false);
            }
        }

        return qr;
    }
};