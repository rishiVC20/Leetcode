class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>expected  = heights;
        sort(expected.begin(),expected.end());
        int cn = 0;
        for (int i=0; i<heights.size(); i++)
        {
            if (heights[i] != expected[i])
                cn++;
        }

        return cn;
    }
};