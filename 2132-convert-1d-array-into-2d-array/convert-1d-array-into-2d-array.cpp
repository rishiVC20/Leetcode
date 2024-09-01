class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz=original.size();
        if(m*n != sz){
            return {};
        }
        vector<vector<int>>v;
        vector<int>p;
        int j=0;
        for(int i=0; i<original.size(); i++){
            p.push_back(original[i]);
            j++;
            if(j==n){
                j=0;
                v.push_back(p);
                p.clear();
            }
        }

        return v;
    }
};