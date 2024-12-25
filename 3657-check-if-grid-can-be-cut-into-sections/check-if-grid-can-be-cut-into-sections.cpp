class Solution {
public:
    bool solve(vector<vector<int>>v){
        sort(v.begin(),v.end());

        vector<vector<int>>merge;
        merge.push_back(v[0]);
        int cn=0;
        for(int i=1; i<v.size(); i++){
            // auto [a,b]=merge.back();
            if(v[i][0] < merge.back()[1]){
                merge.back()[1]=max(v[i][1],merge.back()[1]);
            }
            else{
                merge.push_back(v[i]);
            }
        }

        return merge.size()>=3;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>vx,vy;

        for(auto i:rectangles){
            vector<int>k1,k2;
            k1.push_back(i[0]),k1.push_back(i[2]);
            k2.push_back(i[1]),k2.push_back(i[3]);
            vx.push_back(k1),vy.push_back(k2);
        }

        bool x=solve(vx);
        bool y=solve(vy);

        return x|y;
    }
};