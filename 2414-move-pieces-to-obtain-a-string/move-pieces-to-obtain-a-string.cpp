class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int k1=0,k2=0,g1=0,g2=0;
        for(auto i:start){
            k1+=(i=='L');
            g1+=(i=='R');
        }
        for(auto i:target){
            k2+=(i=='L');
            g2+=(i=='R');
        }
        if(k1!=k2 || g1!=g2)
            return false;
        
        vector<pair<char,int>>v;
        
        for(int i=0; i<n; i++){
            if(start[i]!='_'){
                v.push_back({start[i],i});
            }
        }

        sort(v.begin(),v.end(),[&](pair<char,int> &a, pair<char,int> &b){
            return a.second<b.second;
        });
        // for(auto i:v)
        //     cout<<i.first<<' '<<i.second<<endl;
        int t=0;
        int m=v.size();
        for(int i=0; i<n && t<m; i++){
            if(target[i]=='L' || target[i]=='R'){
                if(target[i]==v[t].first){
                    if(target[i]=='L'){
                        if(i>v[t].second) return false;
                    }
                    else if(target[i]=='R'){
                        if(i<v[t].second) return false;
                    }
                    t++;
                }
                else{
                    return false;
                }
            }
        }

        return true;

        
    }
};