class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>mp;

        int n=matrix.size(),m=matrix[0].size();

        for(int i=0; i<n; i++){
            string s="";
            for(int j=0; j<m; j++){
                s += (matrix[i][j]==matrix[i][0])?'1':'0';
            }
            mp[s]++;
        }

        int maxi=0;
        for(auto i:mp)
            maxi=max(maxi,i.second);


        return maxi;    
    }
};