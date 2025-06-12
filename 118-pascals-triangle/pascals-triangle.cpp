class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>d={1};
        ans.push_back(d);

        for(int i=1; i<numRows; i++){
            vector<int>df=ans.back();
            vector<int>km(df.size()+1);
            km[0]=df[0],km[df.size()]=df[df.size()-1];

            for(int j=1; j<km.size()-1; j++){
                km[j]=df[j]+df[j-1];
            }
            ans.push_back(km);
        }

        return ans;

    }
};