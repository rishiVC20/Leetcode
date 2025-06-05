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
        int findParent(int nd){
            if(nd==par[nd]){
                return nd;
            }
            return par[nd]=findParent(par[nd]);
        }
        void unionBySize(int u, int v){
            int paru=findParent(u);
            int parv=findParent(v);
            if(paru==parv){
                return;
            }
            if(size[paru]>=size[parv]){
                par[parv]=paru;
                size[paru]+=size[parv];
            }
            else{
                par[paru]=parv;
                size[parv]+=paru;
            }
        }
    };
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();

        Disjoint d(26);
        for(int i=0; i<n; i++){
            int k1=s1[i]-'a',k2=s2[i]-'a';
            d.unionBySize(min(k1,k2),max(k1,k2));
        }
        map<int,int>mp;
        for(int i=0; i<26; i++){
            int k1=d.findParent(i);
            if(mp.find(k1)!=mp.end()){
                mp[k1]=min(i,mp[k1]);
            }
            else{
                mp[k1]=min(i,k1);
            }
            // cout<<i<<' '<<mp[i]<<endl;
        }
        string ans="";
        for(int i=0; i<baseStr.size(); i++){
            int kp=d.findParent(baseStr[i]-'a');
            ans+=mp[kp]+'a';
        }

        return ans;
    }
};