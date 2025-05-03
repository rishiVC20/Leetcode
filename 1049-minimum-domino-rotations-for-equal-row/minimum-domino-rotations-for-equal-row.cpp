class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            if(tops[i]==bottoms[i]){
                mp[tops[i]]++;
            }
            else{
                mp[tops[i]]++,mp[bottoms[i]]++;
            }
        }

        int mx=0;
        int j=-1;
        for(auto i:mp){
            if(i.second>mx){
                mx=i.second;
                j=i.first;
            }
        }
        if(mx!=n){
            return -1;
        }
        // cout<<j<<' ';
        int f1=0,f2=0;
        for(int i=0; i<n; i++){
            if(tops[i]!=bottoms[i]){
                // cout<<tops[i]<<' '<<bottoms[j]
                f1+=(tops[i]==j);
                f2+=(bottoms[i]==j);
            }
        }
        // cout<<f1<<' '<<f2;
        return min(f1,f2);
    }
};