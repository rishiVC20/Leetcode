class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int,int>>v;
        for(auto i:meetings){
            v.push_back({i[0],i[1]});
        }
        sort(v.begin(),v.end(),[&](const pair<int,int>&a, const pair<int,int>&b){
            if(a.first==b.first)
                return a.second<b.second;
            return a.first<b.first;
        });
        // for(auto i:v){
        //     cout<<i.first<<' '<<i.second<<endl;
        // }
        vector<pair<int,int>>p;
        int pre=v[0].first,las=v[0].second;
        if(v.size()==1){
            p.push_back({pre,las});
        }
        for(int i=1; i<(int)v.size(); i++){
            if(v[i].first<=las){
                las=max(las,v[i].second);
                
            }
            else{
                p.push_back({pre,las});
                pre=v[i].first,las=v[i].second;
            }
            if(i==(int)v.size()-1){
                p.push_back({pre,las});
            }
        }

        // for(auto i:p){
        //     cout<<i.first<<' '<<i.second<<endl;
        // }
        int cp=p[0].first-1;
        for(int i=1; i<(int)p.size(); i++){
            int t=p[i].first-p[i-1].second-1;
            cp+=t;
            // if(i==(int)p.size()-1){
            //     cp+=days-p[i].second;
            // }
        }
        cp+=days-p[(int)p.size()-1].second;
        return cp;
    }

};